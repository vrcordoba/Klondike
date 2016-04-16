#ifndef CONTROLLERS_COMMAND_HPP_
#define CONTROLLERS_COMMAND_HPP_

#include <vector>
#include <cstdint>
#include "CommandType.hpp"

namespace Controllers
{

class Command final
{
public:
   Command();
   ~Command();

   void setCommandType(CommandType commandType);
   CommandType getCommandType() const;

   void setAdditionalArguments(std::vector<std::uint8_t> additionalArguments);
   std::vector<std::uint8_t> getAdditionalArguments() const;

private:
   CommandType commandTypeM;
   std::vector<std::uint8_t> additionalArgumentsM;
};

}

#endif
