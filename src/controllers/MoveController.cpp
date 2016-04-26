
#include "MoveController.hpp"

#include "MoveCommand.hpp"
#include "DrawCardCommand.hpp"

namespace Controllers
{

MoveController::MoveController(Models::Game& game)
   : Controller(game), movementHistoryM()
{
}

MoveController::~MoveController()
{
}

bool MoveController::isValidMovement(MoveCommand* command)
{
   command->setController(this);
   return command->isValidOrigin() and command->isValidDestination();
}

void MoveController::applyMovement(MoveCommand* command)
{
   movementHistoryM.storeAndExecute(command);
}

void MoveController::applyDrawCard(DrawCardCommand* command)
{
   command->setController(this);
   movementHistoryM.storeAndExecute(command);
}

bool MoveController::validateUndo() const
{
   return movementHistoryM.validateUndo();
}

bool MoveController::validateRedo() const
{
   return movementHistoryM.validateRedo();
}

void MoveController::undo()
{
   movementHistoryM.undo();
}

void MoveController::redo()
{
   movementHistoryM.redo();
}

void MoveController::emptyMovementHistory()
{
   movementHistoryM.emptyHistory();
}

}
