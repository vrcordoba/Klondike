
#include "GameController.hpp"

#include "Command.hpp"
#include "State.hpp"
#include "ValidationCommand.hpp"

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

bool GameController::isValidCommand(Command* command)
{
   command->setController(this);
   bool validCommand = true;
   if (command->doesItHaveToBeValidated())
      validCommand = dynamic_cast<ValidationCommand*>(command)->isValid();
   return validCommand;
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

CardTableController* GameController::getCardTableController()
{
   return &cardTableControllerM;
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
