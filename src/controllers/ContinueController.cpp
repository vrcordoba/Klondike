
#include "ContinueController.hpp"

#include "OperationControllerVisitor.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

ContinueController::ContinueController(Models::Game& game)
   : Controller(game)
{
}

ContinueController::~ContinueController()
{
}

void ContinueController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

void ContinueController::resume(bool otherGame)
{
   if (otherGame)
   {
      Controller::initializeGame();
      Controller::setState(Models::State::GAME);
   }
   else
      Controller::setState(Models::State::END);
}

}

