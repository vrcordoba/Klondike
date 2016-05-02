
#include "AutomaticGameController.hpp"

#include <chrono>
#include <thread>
#include "GameControllerVisitor.hpp"
#include "Command.hpp"
#include "MoveCommand.hpp"
#include "DrawCardCommand.hpp"
#include "LeaveCommand.hpp"
#include "Pile.hpp"
#include "PileType.hpp"

namespace Controllers
{

AutomaticGameController::AutomaticGameController(Models::Game& game) : GameController(game),
   numMovementsM(0)
{
}

AutomaticGameController::~AutomaticGameController()
{
}

GameController* AutomaticGameController::clone()
{
   return new AutomaticGameController(Controller::getGame());
}

void AutomaticGameController::accept(GameControllerVisitor* gameControllerVisitor)
{
   gameControllerVisitor->visit(this);
}

Command* AutomaticGameController::getValidCommand()
{
   if (MAX_MOVEMENTS < ++numMovementsM)
      return new LeaveCommand(LeaveCommand::Type::LEAVE_CLOSE);
   Command* command = getValidCommandTableauFoundation();
   command = (nullptr != command) ? command : getValidCommandWasteFoundation();
   command = (nullptr != command) ? command : getValidCommandWasteTableau();
   command = (nullptr != command) ? command : getValidCommandTableauTableau();
   command = (nullptr != command) ? command : getValidCommandDrawCard();
   std::chrono::duration<std::uint16_t, std::milli> timeToSleep(1000);
   std::this_thread::sleep_for(timeToSleep);
   return command;
}

Command* AutomaticGameController::getValidCommandTableauFoundation()
{
   MoveCommand* moveCommand = nullptr;
   for (std::uint8_t i = 0; (nullptr == moveCommand) and
      (i < Controller::getNumTableaus()) and
      (0 < Controller::getTableau(i)->getNumCards()); ++i)
   {
      for (std::uint8_t j = 0; (nullptr == moveCommand) and j < Controller::getNumFoundations(); ++j)
      {
         std::vector<std::uint8_t> additionalArguments{
            Models::PileType::TABLEAU, static_cast<std::uint8_t>(i + 1),
               Models::PileType::FOUNDATION, static_cast<std::uint8_t>(j + 1), 1};
         moveCommand = getValidMovementCommand(additionalArguments);
      }
   }
   return moveCommand;
}

Command* AutomaticGameController::getValidCommandWasteFoundation()
{
   if (0 == Controller::getWaste()->getNumCards())
      return nullptr;
   MoveCommand* moveCommand = nullptr;
   for (std::uint8_t i = 1; (nullptr == moveCommand) and i <= Controller::getNumFoundations(); ++i)
   {
      std::vector<std::uint8_t> additionalArguments{
         Models::PileType::WASTE, 1, Models::PileType::FOUNDATION, i, 1};
      moveCommand = getValidMovementCommand(additionalArguments);
   }
   return moveCommand;
}

Command* AutomaticGameController::getValidCommandWasteTableau()
{
   if (0 == Controller::getWaste()->getNumCards())
      return nullptr;
   MoveCommand* moveCommand = nullptr;
   for (std::uint8_t i = 1; (nullptr == moveCommand) and i <= Controller::getNumTableaus(); ++i)
   {
      std::vector<std::uint8_t> additionalArguments{
         Models::PileType::WASTE, 1, Models::PileType::TABLEAU, i, 1};
      moveCommand = getValidMovementCommand(additionalArguments);
   }
   return moveCommand;
}

Command* AutomaticGameController::getValidCommandTableauTableau()
{
   MoveCommand* moveCommand = nullptr;
   for (std::uint8_t i = 0; (nullptr == moveCommand) and (i < Controller::getNumTableaus()); ++i)
   {
      for (std::uint8_t j = 0; (nullptr == moveCommand) and (j < Controller::getNumTableaus()); ++j)
      {
         moveCommand = getValidCommandTableauTableauNumCards(i, j);
         if (nullptr == moveCommand)
            moveCommand = getValidCommandTableauTableauNumCards(j, i);
         if (nullptr != moveCommand and isMoveCommandInRecentCommandHistory(moveCommand))
         {
            delete moveCommand;
            moveCommand = nullptr;
         }
      }
   }
   return moveCommand;
}

MoveCommand* AutomaticGameController::getValidCommandTableauTableauNumCards(
   std::uint8_t originTableauId, std::uint8_t destinationTableauId)
{
   MoveCommand* moveCommand = nullptr;
   for (std::uint8_t i = Controller::getTableau(originTableauId)->getNumCards();
      (nullptr == moveCommand) and (i > 0); --i)
   {
      std::vector<std::uint8_t> additionalArguments{
         Models::PileType::TABLEAU, static_cast<std::uint8_t>(originTableauId + 1),
            Models::PileType::TABLEAU, static_cast<std::uint8_t>(destinationTableauId + 1), i};
      moveCommand = getValidMovementCommand(additionalArguments);
   }
   return moveCommand;
}

DrawCardCommand* AutomaticGameController::getValidCommandDrawCard()
{
   DrawCardCommand* drawCardCommand = new DrawCardCommand();
   drawCardCommand->setController(this);
   return drawCardCommand;
}

MoveCommand* AutomaticGameController::getValidMovementCommand(
   const std::vector<std::uint8_t>& additionalArguments)
{
   MoveCommand* moveCommand = new MoveCommand();
   moveCommand->setController(this);
   moveCommand->setAdditionalArguments(additionalArguments);
   if (not moveCommand->isValid())
   {
      delete moveCommand;
      moveCommand = nullptr;
   }
   return moveCommand;
}

bool AutomaticGameController::isMoveCommandInRecentCommandHistory(MoveCommand* moveCommand)
{
   return getMovementHistory()->isMoveCommandInRecentCommandHistory(moveCommand, 10);
}

}
