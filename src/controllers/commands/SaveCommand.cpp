
#include "SaveCommand.hpp"

#include "GameController.hpp"

namespace Controllers
{

SaveCommand::SaveCommand()
{
}

SaveCommand::~SaveCommand()
{
}

Command* SaveCommand::clone()
{
   return new SaveCommand();
}

void SaveCommand::execute()
{
   getController()->setState(Models::State::SAVE);
}

}
