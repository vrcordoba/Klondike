#ifndef CONTROLLERS_MANUALGAMECONTROLLER_HPP_
#define CONTROLLERS_MANUALGAMECONTROLLER_HPP_

#include "GameController.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

class GameControllerVisitor;
class Command;

class ManualGameController final : public GameController
{
public:
   explicit ManualGameController(Models::Game& game);
   ~ManualGameController();

   ManualGameController(const ManualGameController&) = delete;
   ManualGameController& operator=(const ManualGameController&) = delete;

   void accept(GameControllerVisitor* gameControllerVisitor);

   GameController* clone();

   bool isValidCommand(Command* command);
};

}

#endif
