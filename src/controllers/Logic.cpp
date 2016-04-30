
#include "Logic.hpp"

#include <algorithm>
#include "OperationController.hpp"
#include "StartController.hpp"
#include "GameController.hpp"
#include "ContinueController.hpp"
#include "SaveController.hpp"
#include "LoadController.hpp"

namespace Controllers
{

Logic::Logic() : gameM()
{
   controllersM.emplace(Models::State::INITIAL, new StartController(gameM));
   controllersM.emplace(Models::State::LOAD, new LoadController(gameM));
   controllersM.emplace(Models::State::GAME, new GameController(gameM));
   controllersM.emplace(Models::State::CONTINUE, new ContinueController(gameM));
   controllersM.emplace(Models::State::SAVE, new SaveController(gameM));
   controllersM.emplace(Models::State::END, nullptr);
}

Logic::~Logic()
{
   std::for_each(std::begin(controllersM), std::end(controllersM),
      [] (std::pair<const Models::State, OperationController*>& pair)
      {
         delete pair.second;
      });
}

OperationController* Logic::getController() const
{
   return controllersM.at(gameM.getState());
}

}
