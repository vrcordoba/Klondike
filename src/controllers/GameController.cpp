
#include "GameController.hpp"

#include "OperationControllerVisitor.hpp"
#include "Command.hpp"
#include "State.hpp"
#include "MoveCommand.hpp"
#include "DrawCardCommand.hpp"
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
   if (Phase::APPLYCOMMAND == phaseM)
      moveControllerM.applyDrawCard(drawCardCommand);
   return true;
}

bool GameController::visit(LeaveCommand* leaveCommand)
{
   if (Phase::APPLYCOMMAND == phaseM)
   {
      moveControllerM.emptyMovementHistory();
      if (LeaveCommand::Type::LEAVE_CLOSE == leaveCommand->getType())
         Controller::setState(Models::State::CONTINUE);
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

bool GameController::visit(SaveCommand* modifyHistoryCommand)
{
   if (Phase::APPLYCOMMAND == phaseM)
   {
      Controller::setState(Models::State::SAVE);
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
   phaseM = Phase::APPLYCOMMAND;
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
