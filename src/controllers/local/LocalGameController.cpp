
#include "LocalGameController.hpp"

#include "OperationControllerVisitor.hpp"
#include "CardTableController.hpp"
#include "Command.hpp"
#include "State.hpp"

namespace Controllers
{

LocalGameController::LocalGameController(Models::Game& game) : LocalController(game),
   localMoveControllerM(game), cardTableControllerM(game), phaseM(Phase::VALIDATION)
{
}

LocalGameController::~LocalGameController()
{
}

void LocalGameController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

bool LocalGameController::visit(MoveCommand* moveCommand)
{
   if (Phase::VALIDATION == phaseM)
      return localMoveControllerM.isValidMovement(moveCommand);
   else
      localMoveControllerM.applyMovement(moveCommand);
   return true;
}

bool LocalGameController::visit(DrawCardCommand* drawCardCommand)
{
   if (Phase::APPLY_MOVEMENT == phaseM)
      localMoveControllerM.applyDrawCard(drawCardCommand);
   return true;
}

bool LocalGameController::isValidCommand(Command* command)
{
   phaseM = Phase::VALIDATION;
   return command->accept(this);
}

void LocalGameController::applyCommand(Command* command)
{
   phaseM = Phase::APPLY_MOVEMENT;
   command->accept(this);

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
