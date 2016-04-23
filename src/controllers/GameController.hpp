#ifndef CONTROLLERS_GAMECONTROLLER_HPP_
#define CONTROLLERS_GAMECONTROLLER_HPP_

#include "Controller.hpp"
#include "CommandVisitor.hpp"
#include "OperationController.hpp"
#include "CardTableController.hpp"
#include "MoveController.hpp"

namespace Controllers
{

class OperationControllerVisitor;
class Command;
class MoveCommand;
class DrawCardCommand;
class LeaveCommand;
class ModifyHistoryCommand;

class GameController final : public Controller, public CommandVisitor, public OperationController
{
public:
   explicit GameController(Models::Game& game);
   ~GameController();

   GameController(const GameController&) = delete;
   GameController& operator=(const GameController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   bool visit(MoveCommand* moveCommand);
   bool visit(DrawCardCommand* drawCardCommand);
   bool visit(LeaveCommand* leaveCommand);
   bool visit(ModifyHistoryCommand* modifyHistoryCommand);

   bool isValidCommand(Command* command);
   void applyCommand(Command* command);
   bool isGameWon() const;

   CardTableController* getCardTableController();

private:
   MoveController moveControllerM;
   CardTableController cardTableControllerM;

   enum class Phase
   {
      VALIDATION,
      APPLY_MOVEMENT
   };
   Phase phaseM;
};

}

#endif
