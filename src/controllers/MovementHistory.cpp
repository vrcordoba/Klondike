
#include "MovementHistory.hpp"

namespace Controllers
{

MovementHistory::MovementHistory() : undoableHistoryM(), redoableHistoryM()
{
}

MovementHistory::~MovementHistory()
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

void MovementHistory::storeAndExecute(CardCommand* command)
{
   undoableHistoryM.push_back(command);
   emptyHistory(redoableHistoryM);
   command->execute();
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

CardCommand* MovementHistory::getCommandToUndo()
{
   return undoableHistoryM.back();
}

CardCommand* MovementHistory::getCommandToRedo()
{
   return redoableHistoryM.back();
}

}
