
#include "Logic.hpp"

#include "OperationController.hpp"
#include "StartController.hpp"
#include "GameController.hpp"
#include "ContinueController.hpp"

namespace Controllers
{

Logic::Logic() : gameM()
{
   startControllerM = new StartController(gameM);
   gameControllerM = new GameController(gameM);
   continueControllerM = new ContinueController(gameM);
}

Logic::~Logic()
{
   delete startControllerM;
   delete gameControllerM;
   delete continueControllerM;
}

OperationController* Logic::getController() const
{
   switch (gameM.getState())
   {
      case Models::State::INITIAL:
         return startControllerM;
      case Models::State::GAME:
         return gameControllerM;
      case Models::State::CONTINUE:
         return continueControllerM;
      case Models::State::END:
      default:
         return nullptr;
   }
}

}
