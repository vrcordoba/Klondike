
#include "AutomaticGameController.hpp"

#include "GameControllerVisitor.hpp"

namespace Controllers
{

AutomaticGameController::AutomaticGameController(Models::Game& game) : GameController(game)
{
}

AutomaticGameController::~AutomaticGameController()
{
}

GameController* AutomaticGameController::clone()
{
   return new AutomaticGameController(Controller::getGame());
}

void AutomaticGameController::accept(GameControllerVisitor* gameControllerVisitor)
{
   gameControllerVisitor->visit(this);
}

void AutomaticGameController::applyCommand()
{
}

}
