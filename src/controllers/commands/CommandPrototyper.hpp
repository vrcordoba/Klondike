#ifndef CONTROLLERS_COMMANDS_COMMANDPROTOTYPER_HPP_
#define CONTROLLERS_COMMANDS_COMMANDPROTOTYPER_HPP_

#include <cstdint>
#include <map>
#include <vector>
#include "CommandType.hpp"

namespace Controllers
{

class Command;

class CommandPrototyper final
{
public:
   CommandPrototyper();
   ~CommandPrototyper();

   Command* getCommand(CommandType commandType,
      const std::vector<std::uint8_t>& additionalArguments) const;

private:
   std::map<CommandType, Command*> commandPrototypesM;
};

}

#endif
