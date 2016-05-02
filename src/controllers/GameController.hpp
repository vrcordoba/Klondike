#ifndef CONTROLLERS_GAMECONTROLLER_HPP_
#define CONTROLLERS_GAMECONTROLLER_HPP_

#include "Controller.hpp"
#include "OperationController.hpp"
#include "CardTableController.hpp"
#include "MovementHistory.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

class OperationControllerVisitor;
class GameControllerVisitor;
class Command;

class GameController : public Controller, public OperationController
{
public:
   explicit GameController(Models::Game& game);
   virtual ~GameController();

   virtual GameController* clone() = 0;

   void accept(OperationControllerVisitor* operationControllerVisitor);
   virtual void accept(GameControllerVisitor* gameControllerVisitor) = 0;

   CardTableController* getCardTableController();
   bool isGameWon() const;

   MovementHistory* getMovementHistory();
   void emptyMovementHistory();

   void applyCommand(Command* command);

private:
   CardTableController cardTableControllerM;
   MovementHistory movementHistoryM;
};

}

#endif
