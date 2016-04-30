
#include "MovementHistory.hpp"

#include "DrawCardCommand.hpp"
#include "MoveCommand.hpp"

namespace Controllers
{

MovementHistory::MovementHistory() : undoableHistoryM(), redoableHistoryM()
{
}

MovementHistory::~MovementHistory()
{
   emptyHistory();
}

void MovementHistory::emptyHistory()
{
   emptyHistory(undoableHistoryM);
   emptyHistory(redoableHistoryM);
}

void MovementHistory::emptyHistory(std::stack<CardCommand*>& history)
{
   while (not history.empty())
   {
      CardCommand* command = history.top();
      history.pop();
      delete command;
   }
}

void MovementHistory::executeAndStoreIfUndoableCommand(Command* command)
{
   command->execute();
   if (command->isUndoable())
   {
      CardCommand* cardCommand = dynamic_cast<CardCommand*>(command);
      cardCommand->accept(this);
      emptyHistory(redoableHistoryM);
   }
}

void MovementHistory::visit(DrawCardCommand* drawCardCommand)
{
   // A copy is done to make the memory handling easier
   DrawCardCommand* copy = new DrawCardCommand(*drawCardCommand);
   undoableHistoryM.push(copy);
}

void MovementHistory::visit(MoveCommand* moveCommand)
{
   // A copy is done to make the memory handling easier
   MoveCommand* copy = new MoveCommand(*moveCommand);
   undoableHistoryM.push(copy);
}

bool MovementHistory::validateUndo() const
{
   return not undoableHistoryM.empty();
}

bool MovementHistory::validateRedo() const
{
   return not redoableHistoryM.empty();
}

void MovementHistory::undo()
{
   CardCommand* command = undoableHistoryM.top();
   undoableHistoryM.pop();
   command->undo();
   redoableHistoryM.push(command);
}

void MovementHistory::redo()
{
   CardCommand* command = redoableHistoryM.top();
   redoableHistoryM.pop();
   command->execute();
   undoableHistoryM.push(command);
}

}
