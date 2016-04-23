#ifndef CONTROLLERS_MOVECONTROLLER_HPP_
#define CONTROLLERS_MOVECONTROLLER_HPP_

#include "Controller.hpp"
#include "MovementHistory.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

class MoveCommand;
class DrawCardCommand;

class MoveController final : public Controller
{
public:
   explicit MoveController(Models::Game& game);
   ~MoveController();

   MoveController(const MoveController&) = delete;
   MoveController& operator=(const MoveController&) = delete;

   bool isValidMovement(MoveCommand* command);
   void applyMovement(MoveCommand* command);
   void applyDrawCard(DrawCardCommand* command);

private:
   void updateScore(MoveCommand* command, bool upturnScore);

   MovementHistory movementHistoryM;
};

}

#endif
