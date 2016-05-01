#ifndef CONTROLLERS_GAMECONTROLLERPROTOTYPER_HPP_
#define CONTROLLERS_GAMECONTROLLERPROTOTYPER_HPP_

#include <cstdint>
#include <map>
#include "GameController.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

class GameControllerPrototyper
{
public:
   explicit GameControllerPrototyper(Models::Game& game);
   ~GameControllerPrototyper();

   GameController* getGameController(std::uint8_t numPlayers) const;

private:
   std::map<const std::uint8_t, GameController*> gameControllerPrototypesM;
};

}

#endif
