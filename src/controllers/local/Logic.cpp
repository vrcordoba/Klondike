
#include "Logic.hpp"

#include "OperationController.hpp"
#include "LocalStartController.hpp"
#include "LocalContinueController.hpp"

namespace Controllers
{

Logic::Logic() : gameM(), deckBuilderM()
{
   startControllerM = new LocalStartController(gameM, deckBuilderM);
   continueControllerM = new LocalContinueController();
}

Logic::~Logic()
{
   delete startControllerM;
   delete continueControllerM;
}

OperationController* Logic::getController() const
{
   switch (gameM.getState())
   {
      case Models::State::INITIAL:
         return startControllerM;
      case Models::State::CONTINUE_GAME:
         return continueControllerM;
      case Models::State::END_GAME:
      default:
         return nullptr;
   }
}

}
