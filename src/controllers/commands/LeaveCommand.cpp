
#include "LeaveCommand.hpp"

#include "ManualGameController.hpp"

namespace Controllers
{

LeaveCommand::LeaveCommand(Type type) : typeM(type)
{
}

LeaveCommand::~LeaveCommand()
{
}

Command* LeaveCommand::clone()
{
   return new LeaveCommand(typeM);
}

void LeaveCommand::execute()
{
   getController()->emptyMovementHistory();
   if (LeaveCommand::Type::LEAVE_CLOSE == typeM)
      getController()->setState(Models::State::CONTINUE);
   else
      getController()->initializeGame();
}

}
