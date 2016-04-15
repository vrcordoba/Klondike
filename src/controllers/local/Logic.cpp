
#include "Logic.hpp"

#include "OperationController.hpp"
#include "LocalStartController.hpp"
#include "LocalGameController.hpp"
#include "LocalContinueController.hpp"

namespace Controllers
{

Logic::Logic() : gameM()
{
   startControllerM = new LocalStartController(gameM);
   gameControllerM = new LocalGameController(gameM);
   continueControllerM = new LocalContinueController(gameM);
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
      case Models::State::CONTINUE_GAME:
         return continueControllerM;
      case Models::State::END_GAME:
      default:
         return nullptr;
   }
}

}
