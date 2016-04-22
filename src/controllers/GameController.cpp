
#include "GameController.hpp"

#include "OperationControllerVisitor.hpp"
#include "CardTableController.hpp"
#include "Command.hpp"
#include "State.hpp"
#include "LeaveCommand.hpp"

namespace Controllers
{

GameController::GameController(Models::Game& game) : Controller(game),
   localMoveControllerM(game), cardTableControllerM(game), phaseM(Phase::VALIDATION)
{
}

GameController::~GameController()
{
}

void GameController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

bool GameController::visit(MoveCommand* moveCommand)
{
   if (Phase::VALIDATION == phaseM)
      return localMoveControllerM.isValidMovement(moveCommand);
   else
      localMoveControllerM.applyMovement(moveCommand);
   return true;
}

bool GameController::visit(DrawCardCommand* drawCardCommand)
{
   if (Phase::APPLY_MOVEMENT == phaseM)
      localMoveControllerM.applyDrawCard(drawCardCommand);
   return true;
}

bool GameController::visit(LeaveCommand* leaveCommand)
{
   if (Phase::APPLY_MOVEMENT == phaseM)
   {
      if (LeaveCommand::Type::LEAVE_CLOSE == leaveCommand->getType())
         Controller::setState(Models::State::END);
      else
         Controller::initializeGame();
   }
   return true;
}

bool GameController::isValidCommand(Command* command)
{
   phaseM = Phase::VALIDATION;
   return command->accept(this);
}

void GameController::applyCommand(Command* command)
{
   phaseM = Phase::APPLY_MOVEMENT;
   command->accept(this);

   if (Controller::isGameWon())
      Controller::setState(Models::State::CONTINUE);
}

CardTableController* GameController::getCardTableController()
{
   return &cardTableControllerM;
}

bool GameController::isGameWon() const
{
   return Controller::isGameWon();
}

}
