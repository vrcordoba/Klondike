
#include "LocalGameController.hpp"

#include "OperationControllerVisitor.hpp"
#include "CardTableController.hpp"
#include "Command.hpp"
#include "State.hpp"

namespace Controllers
{

LocalGameController::LocalGameController(Models::Game& game) : LocalController(game),
   localMoveControllerM(game), cardTableControllerM(game)
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
      return localMoveControllerM.isValidMovement(command);
   }
   return true;
}

void LocalGameController::applyCommand(const Command& command)
{
   if (CommandType::MOVE == command.getCommandType())
      localMoveControllerM.applyMovement(command);
   else if (CommandType::DRAWCARD  == command.getCommandType())
      localMoveControllerM.applyDrawCard(command);

   if (LocalController::isGameWon())
      LocalController::setState(Models::State::END_GAME);
}

CardTableController* LocalGameController::getCardTableController()
{
   return &cardTableControllerM;
}

bool LocalGameController::isGameWon() const
{
   return LocalController::isGameWon();
}

}
