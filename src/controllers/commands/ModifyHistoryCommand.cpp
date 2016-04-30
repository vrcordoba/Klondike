
#include "ModifyHistoryCommand.hpp"

#include "GameController.hpp"
#include "MovementHistory.hpp"

namespace Controllers
{

ModifyHistoryCommand::ModifyHistoryCommand(Type type) : typeM(type)
{
}

ModifyHistoryCommand::~ModifyHistoryCommand()
{
}

Command* ModifyHistoryCommand::clone()
{
   return new ModifyHistoryCommand(typeM);
}

bool ModifyHistoryCommand::isValid()
{
   bool isValid;
   MovementHistory* movementHistory = getController()->getMovementHistory();
   if (Type::REDO == typeM)
      isValid = movementHistory->validateRedo();
   else
      isValid = movementHistory->validateUndo();
   return isValid;
}

void ModifyHistoryCommand::execute()
{
   MovementHistory* movementHistory = getController()->getMovementHistory();
   if (Type::REDO == typeM)
      movementHistory->redo();
   else
      movementHistory->undo();
}

}
