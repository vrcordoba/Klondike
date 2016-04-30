#ifndef CONTROLLERS_GAMECONTROLLER_HPP_
#define CONTROLLERS_GAMECONTROLLER_HPP_

#include "Controller.hpp"
#include "OperationController.hpp"
#include "CardTableController.hpp"
#include "MovementHistory.hpp"

namespace Controllers
{

class OperationControllerVisitor;
class Command;

class GameController final : public Controller, public OperationController
{
public:
   explicit GameController(Models::Game& game);
   ~GameController();

   GameController(const GameController&) = delete;
   GameController& operator=(const GameController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   bool isValidCommand(Command* command);
   void applyCommand(Command* command);
   bool isGameWon() const;

   CardTableController* getCardTableController();

   MovementHistory* getMovementHistory();
   void emptyMovementHistory();

private:
   CardTableController cardTableControllerM;
   MovementHistory movementHistoryM;
};

}

#endif
