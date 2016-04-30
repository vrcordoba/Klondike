#ifndef CONTROLLERS_COMMANDS_MOVEMENTHISTORY_HPP_
#define CONTROLLERS_COMMANDS_MOVEMENTHISTORY_HPP_

#include <stack>
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

   void visit(DrawCardCommand* drawCardCommand);
   void visit(MoveCommand* moveCommand);

private:
   void emptyHistory(std::stack<CardCommand*>& history);

   std::stack<CardCommand*> undoableHistoryM;
   std::stack<CardCommand*> redoableHistoryM;
};

}

#endif
