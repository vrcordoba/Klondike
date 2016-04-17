
#include "CommandManager.hpp"

#include <cassert>
#include "DrawCardCommand.hpp"
#include "MoveCommand.hpp"

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
   else
      assert(false);
   return command;
}

}
