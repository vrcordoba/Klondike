
#include "GameController.hpp"

#include "OperationControllerVisitor.hpp"
#include "CardTableController.hpp"
#include "Command.hpp"
#include "State.hpp"
#include "LeaveCommand.hpp"
#include "ModifyHistoryCommand.hpp"

namespace Controllers
{

GameController::GameController(Models::Game& game) : Controller(game),
   moveControllerM(game), cardTableControllerM(game), phaseM(Phase::VALIDATION)
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
      return moveControllerM.isValidMovement(moveCommand);
   else
      moveControllerM.applyMovement(moveCommand);
   return true;
}

bool GameController::visit(DrawCardCommand* drawCardCommand)
{
   if (Phase::APPLY_MOVEMENT == phaseM)
      moveControllerM.applyDrawCard(drawCardCommand);
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

bool GameController::visit(ModifyHistoryCommand* modifyHistoryCommand)
{
   if (Phase::VALIDATION == phaseM)
   {
      if (ModifyHistoryCommand::Type::UNDO == modifyHistoryCommand->getType())
         return moveControllerM.validateUndo();
      else
         return moveControllerM.validateRedo();
   }
   else
   {
      if (ModifyHistoryCommand::Type::UNDO == modifyHistoryCommand->getType())
         moveControllerM.undo();
      else
         moveControllerM.redo();
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
