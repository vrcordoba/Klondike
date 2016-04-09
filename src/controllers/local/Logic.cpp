
#include "Logic.hpp"

#include "OperationController.hpp"
#include "LocalStartController.hpp"

namespace Controllers
{

Logic::Logic() : gameM(), deckBuilderM()
{
   startControllerM = new LocalStartController(gameM, deckBuilderM);
}

Logic::~Logic()
{
   delete startControllerM;
}

OperationController* Logic::getController() const
{
   switch (gameM.getState())
   {
      case Models::State::INITIAL:
         return startControllerM;
      default:
         return nullptr;
   }
}

}
