
#include "SaveCommand.hpp"

#include "CommandVisitor.hpp"

namespace Controllers
{

SaveCommand::SaveCommand()
{
}

SaveCommand::~SaveCommand()
{
}

bool SaveCommand::accept(CommandVisitor* commandVisitor)
{
   return commandVisitor->visit(this);
}

}
