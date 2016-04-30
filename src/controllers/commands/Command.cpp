
#include "Command.hpp"

#include <cassert>

namespace Controllers
{

Command::Command() : gameControllerM(nullptr)
{
}

Command::~Command()
{
}

void Command::setController(GameController* gameController)
{
   gameControllerM = gameController;
}

GameController* Command::getController() const
{
   assert(nullptr != gameControllerM);
   return gameControllerM;
}

bool Command::doesItHaveToBeValidated()
{
   return false;
}

bool Command::isUndoable()
{
   return false;
}

}
