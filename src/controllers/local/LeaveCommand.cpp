
#include "LeaveCommand.hpp"

#include "CommandVisitor.hpp"

namespace Controllers
{

LeaveCommand::LeaveCommand(Type type) : typeM(type)
{
}

LeaveCommand::~LeaveCommand()
{
}

bool LeaveCommand::accept(CommandVisitor* commandVisitor)
{
   return commandVisitor->visit(this);
}

LeaveCommand::Type LeaveCommand::getType() const
{
   return typeM;
}

}
