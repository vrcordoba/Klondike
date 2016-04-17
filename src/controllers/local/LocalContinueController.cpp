
#include "LocalContinueController.hpp"

#include "OperationControllerVisitor.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

LocalContinueController::LocalContinueController(Models::Game& game)
   : LocalController(game)
{
}

LocalContinueController::~LocalContinueController()
{
}

void LocalContinueController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

void LocalContinueController::resume(bool otherGame)
{
   if (otherGame)
   {
      LocalController::initializeGame();
      LocalController::setState(Models::State::GAME);
   }
   else
      LocalController::setState(Models::State::END);
}

}

