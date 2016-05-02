#ifndef CONTROLLERS_COMMANDS_MOVEMENTHISTORY_HPP_
#define CONTROLLERS_COMMANDS_MOVEMENTHISTORY_HPP_

#include <deque>
#include "CardCommand.hpp"
#include "CardCommandVisitor.hpp"

namespace Controllers
{

class Command;
class DrawCardCommand;
class MoveCommand;

class MovementHistory final : public CardCommandVisitor
{
public:
   MovementHistory();
   virtual ~MovementHistory();

   MovementHistory(const MovementHistory&) = delete;
   MovementHistory& operator=(const MovementHistory&) = delete;

   void executeAndStoreIfUndoableCommand(Command* command);

   bool validateUndo() const;
   bool validateRedo() const;
   void undo();
   void redo();

   void emptyHistory();

   bool isMoveCommandInRecentCommandHistory(MoveCommand* command,
      std::uint32_t maxNumMovementsToCheck);

   void visit(DrawCardCommand* drawCardCommand);
   void visit(MoveCommand* moveCommand);

private:
   void emptyHistory(std::deque<CardCommand*>& history);

   std::deque<CardCommand*> undoableHistoryM;
   std::deque<CardCommand*> redoableHistoryM;
};

}

#endif
