
#include "ModifyHistoryCommand.hpp"

#include "CommandVisitor.hpp"

namespace Controllers
{

ModifyHistoryCommand::ModifyHistoryCommand(Type type) : typeM(type)
{
}

ModifyHistoryCommand::~ModifyHistoryCommand()
{
}

bool ModifyHistoryCommand::accept(CommandVisitor* commandVisitor)
{
   return commandVisitor->visit(this);
}

ModifyHistoryCommand::Type ModifyHistoryCommand::getType() const
{
   return typeM;
}

}
