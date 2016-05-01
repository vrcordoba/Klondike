#ifndef CONTROLLERS_AUTOMATICGAMECONTROLLER_HPP_
#define CONTROLLERS_AUTOMATICGAMECONTROLLER_HPP_

#include "GameController.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

class GameControllerVisitor;

class AutomaticGameController: public GameController
{
public:
   explicit AutomaticGameController(Models::Game& game);
   ~AutomaticGameController();

   GameController* clone();

   void accept(GameControllerVisitor* gameControllerVisitor);

   void applyCommand();
};

}

#endif
