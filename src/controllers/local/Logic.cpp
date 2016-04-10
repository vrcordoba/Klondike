
#include "Logic.hpp"

#include "OperationController.hpp"
#include "LocalStartController.hpp"
#include "LocalMoveController.hpp"
#include "LocalContinueController.hpp"

namespace Controllers
{

Logic::Logic() : gameM()
{
   startControllerM = new LocalStartController(gameM);
   moveControllerM = new LocalMoveController(gameM);
   continueControllerM = new LocalContinueController(gameM);
}

Logic::~Logic()
{
   delete startControllerM;
   delete moveControllerM;
   delete continueControllerM;
}

OperationController* Logic::getController() const
{
   switch (gameM.getState())
   {
      case Models::State::INITIAL:
         return startControllerM;
      case Models::State::MOVE:
         return moveControllerM;
      case Models::State::CONTINUE_GAME:
         return continueControllerM;
      case Models::State::END_GAME:
      default:
         return nullptr;
   }
}

}
