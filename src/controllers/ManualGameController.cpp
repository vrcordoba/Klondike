
#include "ManualGameController.hpp"

#include "GameControllerVisitor.hpp"
#include "Command.hpp"
#include "ValidationCommand.hpp"

namespace Controllers
{

ManualGameController::ManualGameController(Models::Game& game) : GameController(game)
{
}

ManualGameController::~ManualGameController()
{
}

GameController* ManualGameController::clone()
{
   return new ManualGameController(Controller::getGame());
}

void ManualGameController::accept(GameControllerVisitor* gameControllerVisitor)
{
   gameControllerVisitor->visit(this);
}

bool ManualGameController::isValidCommand(Command* command)
{
   command->setController(this);
   bool validCommand = true;
   if (command->doesItHaveToBeValidated())
      validCommand = dynamic_cast<ValidationCommand*>(command)->isValid();
   return validCommand;
}

}
