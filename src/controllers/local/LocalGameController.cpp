
#include "LocalGameController.hpp"

#include "OperationControllerVisitor.hpp"
#include "CardTableController.hpp"
#include "Command.hpp"
#include "MovementOriginDestinationType.hpp"
#include "Pile.hpp"

namespace Controllers
{

LocalGameController::LocalGameController(Models::Game& game) : LocalController(game),
   cardTableControllerM(game)
{
}

LocalGameController::~LocalGameController()
{
}

void LocalGameController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

bool LocalGameController::isValidCommand(const Command& command) const
{
   if (CommandType::MOVE == command.getCommandType())
   {
      return isValidMovement(command);
   }
   return true;
}

bool LocalGameController::isValidMovement(const Command& command) const
{
   std::vector<std::uint8_t> additionalArguments = command.getAdditionalArguments();
   if (isValidOrigin(additionalArguments[0], additionalArguments[1]))
   {
      return isValidDestination(additionalArguments);
   }
   return false;
}

bool LocalGameController::isValidOrigin(std::uint8_t originPile, std::uint8_t originIndex) const
{
   return isIndexValid(originPile, originIndex);
}

bool LocalGameController::isIndexValid(std::uint8_t pile, std::uint8_t index) const
{
   bool isIndexValid = true;
   if (MovementOriginDestinationType::TABLEAU == pile)
   {
      isIndexValid = (LocalController::getNumTableaus() >= index and 0 < index);
   }
   else if (MovementOriginDestinationType::FOUNDATION == pile)
   {
      isIndexValid = (LocalController::getNumFoundations() >= index and 0 < index);
   }
   return isIndexValid;
}

bool LocalGameController::isValidDestination(
   const std::vector<std::uint8_t>& additionalArguments) const
{
   if (isIndexValid(additionalArguments[2], additionalArguments[3]))
   {
      return isCardStackableInDestination(additionalArguments);
   }
   return false;
}

bool LocalGameController::isCardStackableInDestination(
   const std::vector<std::uint8_t>& additionalArguments) const
{
   Models::Card cardToMove = getCardToMove(additionalArguments);
   Models::Pile* destinationPile = getPile(additionalArguments[2],
      additionalArguments[3]);
   return destinationPile->isValidDestination(cardToMove);
}

Models::Card LocalGameController::getCardToMove(
   const std::vector<std::uint8_t>& additionalArguments) const
{
   Models::Pile* originPile = getPile(additionalArguments[0],
      additionalArguments[1]);
   return originPile->getCardAt(
      originPile->getNumCards() - additionalArguments[4]);
}

Models::Pile* LocalGameController::getPile(std::uint8_t pileId,
   std::uint8_t pileIndex) const
{
   Models::Pile* pile;
   if (MovementOriginDestinationType::WASTE == pileId)
   {
      pile = LocalController::getWaste();
   }
   else if (MovementOriginDestinationType::FOUNDATION == pileId)
   {
      pile = LocalController::getFoundation(pileIndex - 1);
   }
   else
   {
      pile = LocalController::getTableau(pileIndex - 1);
   }
   return pile;
}

void LocalGameController::applyCommand(const Command& command)
{
   if (CommandType::MOVE == command.getCommandType())
   {
      applyMovement(command);
   }
}

void LocalGameController::applyMovement(const Command& command)
{
   std::vector<std::uint8_t> additionalArguments = command.getAdditionalArguments();
   Models::Pile* originPile = getPile(additionalArguments[0],
      additionalArguments[1]);
   Models::Pile* destinationPile = getPile(additionalArguments[2],
      additionalArguments[3]);
   Models::Pile cardsToMove;
   for (std::uint8_t i = 0; i < additionalArguments[4]; ++i)
   {
      cardsToMove.addCard(originPile->takeCard());
   }
   for (std::uint8_t i = 0; i < additionalArguments[4]; ++i)
   {
      LocalController::transferCard(cardsToMove, *destinationPile);
   }
}

CardTableController* LocalGameController::getCardTableController()
{
   return &cardTableControllerM;
}

}
