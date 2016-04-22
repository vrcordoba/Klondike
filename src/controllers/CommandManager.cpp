
#include "CommandManager.hpp"

#include <cassert>
#include "DrawCardCommand.hpp"
#include "MoveCommand.hpp"
#include "LeaveCommand.hpp"

namespace Controllers
{

CommandManager::CommandManager()
{
}

CommandManager::~CommandManager()
{
}

Command* CommandManager::getCommand(CommandType commandType,
   const std::vector<std::uint8_t>& additionalArguments) const
{
   Command* command;
   if (CommandType::DRAWCARD == commandType)
      command = new DrawCardCommand();
   else if (CommandType::MOVE == commandType)
      command = new MoveCommand(additionalArguments);
   else if (CommandType::LEAVE == commandType)
      command = new LeaveCommand(LeaveCommand::Type::LEAVE_CLOSE);
   else if (CommandType::RESTART == commandType)
      command = new LeaveCommand(LeaveCommand::Type::LEAVE_RESTART);
   else
      assert(false);
   return command;
}

}
