
#include "CommandPrototyper.hpp"

#include <cassert>
#include <algorithm>
#include "DrawCardCommand.hpp"
#include "MoveCommand.hpp"
#include "SaveCommand.hpp"
#include "ModifyHistoryCommand.hpp"
#include "LeaveCommand.hpp"

namespace Controllers
{

CommandPrototyper::CommandPrototyper()
{
   commandPrototypesM.emplace(CommandType::DRAWCARD, new DrawCardCommand());
   commandPrototypesM.emplace(CommandType::MOVE, new MoveCommand());
   commandPrototypesM.emplace(CommandType::SAVE, new SaveCommand());
   commandPrototypesM.emplace(CommandType::UNDO, new ModifyHistoryCommand(ModifyHistoryCommand::Type::UNDO));
   commandPrototypesM.emplace(CommandType::REDO, new ModifyHistoryCommand(ModifyHistoryCommand::Type::REDO));
   commandPrototypesM.emplace(CommandType::LEAVE, new LeaveCommand(LeaveCommand::Type::LEAVE_CLOSE));
   commandPrototypesM.emplace(CommandType::INIT, new LeaveCommand(LeaveCommand::Type::LEAVE_INIT));
}

CommandPrototyper::~CommandPrototyper()
{
   std::for_each(std::begin(commandPrototypesM), std::end(commandPrototypesM),
      [] (std::pair<const CommandType, Command*>& pair)
      {
         delete pair.second;
      });
}

Command* CommandPrototyper::getCommand(CommandType commandType,
   const std::vector<std::uint8_t>& additionalArguments) const
{
   std::map<CommandType, Command*>::const_iterator commandIt =
      commandPrototypesM.find(commandType);
   assert(commandIt != commandPrototypesM.end());
   Command* command = commandIt->second->clone();
   if (CommandType::MOVE == commandType)
      static_cast<MoveCommand*>(command)->setAdditionalArguments(additionalArguments);
   return command;
}

}
