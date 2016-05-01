
#include "GameControllerPrototyper.hpp"

#include <cassert>
#include <algorithm>
#include "AutomaticGameController.hpp"
#include "ManualGameController.hpp"

namespace Controllers
{

GameControllerPrototyper::GameControllerPrototyper(Models::Game& game)
{
   gameControllerPrototypesM.emplace(0, new AutomaticGameController(game));
   gameControllerPrototypesM.emplace(1, new ManualGameController(game));
}

GameControllerPrototyper::~GameControllerPrototyper()
{
   std::for_each(std::begin(gameControllerPrototypesM), std::end(gameControllerPrototypesM),
      [] (std::pair<const std::uint8_t, GameController*>& pair)
      {
         delete pair.second;
      });
}

GameController* GameControllerPrototyper::getGameController(std::uint8_t numPlayers) const
{
   std::map<const std::uint8_t, GameController*>::const_iterator gameControllerIt =
      gameControllerPrototypesM.find(numPlayers);
   assert(gameControllerIt != gameControllerPrototypesM.end());
   GameController* gameController = gameControllerIt->second->clone();
   return gameController;
}

}
