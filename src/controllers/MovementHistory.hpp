#ifndef CONTROLLERS_MOVEMENTHISTORY_HPP_
#define CONTROLLERS_MOVEMENTHISTORY_HPP_

#include <deque>
#include "CardCommand.hpp"

namespace Controllers
{

class MovementHistory final
{
public:
   MovementHistory();
   virtual ~MovementHistory();

   MovementHistory(const MovementHistory&) = delete;
   MovementHistory& operator=(const MovementHistory&) = delete;

   void storeAndExecute(CardCommand* command);

   bool validateUndo() const;
   bool validateRedo() const;
   void undo();
   void redo();

   CardCommand* getCommandToUndo();
   CardCommand* getCommandToRedo();

private:
   void emptyHistory(std::deque<CardCommand*>& history);

   std::deque<CardCommand*> undoableHistoryM;
   std::deque<CardCommand*> redoableHistoryM;
};

}

#endif
