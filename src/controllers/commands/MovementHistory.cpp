
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

void MovementHistory::emptyHistory(std::deque<CardCommand*>& history)
{
   while (not history.empty())
   {
      CardCommand* command = history.back();
      history.pop_back();
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
   undoableHistoryM.push_back(copy);
}

void MovementHistory::visit(MoveCommand* moveCommand)
{
   // A copy is done to make the memory handling easier
   MoveCommand* copy = new MoveCommand(*moveCommand);
   undoableHistoryM.push_back(copy);
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
   CardCommand* command = undoableHistoryM.back();
   undoableHistoryM.pop_back();
   command->undo();
   redoableHistoryM.push_back(command);
}

void MovementHistory::redo()
{
   CardCommand* command = redoableHistoryM.back();
   redoableHistoryM.pop_back();
   command->execute();
   undoableHistoryM.push_back(command);
}

bool MovementHistory::isMoveCommandInRecentCommandHistory(MoveCommand* command,
   std::uint32_t maxNumMovementsToCheck)
{
   std::uint32_t numMovements = 0;
   for (std::deque<CardCommand*>::const_reverse_iterator rCommandIt =
      undoableHistoryM.rbegin(); rCommandIt != undoableHistoryM.rend() and
      numMovements < maxNumMovementsToCheck; ++rCommandIt, ++numMovements)
   {
      if (*command == *(*rCommandIt))
         return true;
   }
   return false;
}

}
