
#include "LocalGameController.hpp"

#include "OperationControllerVisitor.hpp"
#include "CardTableController.hpp"
#include "Command.hpp"

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
   {
      localMoveControllerM.applyMovement(command);
   }
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
