
#include "DrawCardCommand.hpp"

#include "CommandVisitor.hpp"

namespace Controllers
{

DrawCardCommand::DrawCardCommand()
{
}

DrawCardCommand::~DrawCardCommand()
{
}

bool DrawCardCommand::accept(CommandVisitor* commandVisitor)
{
   return commandVisitor->visit(this);
}

}
