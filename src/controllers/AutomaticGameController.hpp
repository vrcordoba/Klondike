#ifndef CONTROLLERS_AUTOMATICGAMECONTROLLER_HPP_
#define CONTROLLERS_AUTOMATICGAMECONTROLLER_HPP_

#include <cstdint>
#include <vector>
#include "GameController.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

class GameControllerVisitor;
class Command;
class MoveCommand;
class DrawCardCommand;

class AutomaticGameController: public GameController
{
public:
   explicit AutomaticGameController(Models::Game& game);
   ~AutomaticGameController();

   GameController* clone();

   void accept(GameControllerVisitor* gameControllerVisitor);

   Command* getValidCommand();

private:
   Command* getValidCommandTableauFoundation();
   Command* getValidCommandWasteFoundation();
   Command* getValidCommandTableauTableau();
   Command* getValidCommandWasteTableau();
   DrawCardCommand* getValidCommandDrawCard();
   MoveCommand* getValidMovementCommand(const std::vector<std::uint8_t>& additionalArguments);

   std::uint16_t numMovementsM;
   const std::uint16_t MAX_MOVEMENTS = 1000;
};

}

#endif
