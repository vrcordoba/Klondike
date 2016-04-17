#ifndef CONTROLLERS_LOCAL_LOCALGAMECONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALGAMECONTROLLER_HPP_

#include "GameController.hpp"
#include "LocalController.hpp"
#include "LocalCardTableController.hpp"
#include "LocalMoveController.hpp"
#include "CommandVisitor.hpp"

namespace Controllers
{

class OperationControllerVisitor;
class CardTableController;
class Command;
class MoveCommand;
class DrawCardCommand;
class LeaveCommand;

class LocalGameController final : public GameController,
   public LocalController, public CommandVisitor
{
public:
   explicit LocalGameController(Models::Game& game);
   ~LocalGameController();

   LocalGameController(const LocalGameController&) = delete;
   LocalGameController& operator=(const LocalGameController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   bool visit(MoveCommand* moveCommand);
   bool visit(DrawCardCommand* drawCardCommand);
   bool visit(LeaveCommand* leaveCommand);

   bool isValidCommand(Command* command);
   void applyCommand(Command* command);
   bool isGameWon() const;

   CardTableController* getCardTableController();

private:
   LocalMoveController localMoveControllerM;
   LocalCardTableController cardTableControllerM;

   enum class Phase
   {
      VALIDATION,
      APPLY_MOVEMENT
   };
   Phase phaseM;
};

}

#endif
