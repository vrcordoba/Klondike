
#include "GameController.hpp"

#include "OperationControllerVisitor.hpp"
#include "Command.hpp"
#include "State.hpp"

namespace Controllers
{

GameController::GameController(Models::Game& game) : Controller(game),
   cardTableControllerM(game), movementHistoryM()
{
}

GameController::~GameController()
{
}

void GameController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

CardTableController* GameController::getCardTableController()
{
   return &cardTableControllerM;
}

void GameController::applyCommand(Command* command)
{
   command->setController(this);
   movementHistoryM.executeAndStoreIfUndoableCommand(command);
   if (Controller::isGameWon())
      Controller::setState(Models::State::CONTINUE);
}

bool GameController::isGameWon() const
{
   return Controller::isGameWon();
}

MovementHistory* GameController::getMovementHistory()
{
   return &movementHistoryM;
}

void GameController::emptyMovementHistory()
{
   movementHistoryM.emptyHistory();
}

}
