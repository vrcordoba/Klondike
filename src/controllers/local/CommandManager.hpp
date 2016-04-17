#ifndef CONTROLLERS_LOCAL_COMMANDMANAGER_HPP_
#define CONTROLLERS_LOCAL_COMMANDMANAGER_HPP_

#include <vector>
#include <cstdint>
#include "CommandType.hpp"

namespace Controllers
{

class Command;

class CommandManager final
{
public:
   CommandManager();
   ~CommandManager();

   Command* getCommand(CommandType commandType,
      const std::vector<std::uint8_t>& additionalArguments) const;
};

}

#endif
