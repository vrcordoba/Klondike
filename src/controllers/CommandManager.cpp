
#include "CommandManager.hpp"

#include <cassert>
#include "DrawCardCommand.hpp"
#include "MoveCommand.hpp"
#include "LeaveCommand.hpp"
#include "ModifyHistoryCommand.hpp"
#include "SaveCommand.hpp"

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
   else if (CommandType::SAVE == commandType)
      command = new SaveCommand();
   else if (CommandType::UNDO == commandType)
      command = new ModifyHistoryCommand(ModifyHistoryCommand::Type::UNDO);
   else if (CommandType::REDO == commandType)
      command = new ModifyHistoryCommand(ModifyHistoryCommand::Type::REDO);
   else if (CommandType::LEAVE == commandType)
      command = new LeaveCommand(LeaveCommand::Type::LEAVE_CLOSE);
   else if (CommandType::INIT == commandType)
      command = new LeaveCommand(LeaveCommand::Type::LEAVE_INIT);
   else
      assert(false);
   return command;
}

}
