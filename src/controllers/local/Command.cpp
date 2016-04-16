
#include "Command.hpp"

namespace Controllers
{

Command::Command() : commandTypeM(CommandType::ERROR), additionalArgumentsM()
{

}

Command::~Command()
{
}

void Command::setCommandType(CommandType commandType)
{
   commandTypeM = commandType;
}

CommandType Command::getCommandType() const
{
   return commandTypeM;
}

void Command::setAdditionalArguments(std::vector<std::uint8_t> additionalArguments)
{
   additionalArgumentsM = additionalArguments;
}

std::vector<std::uint8_t> Command::getAdditionalArguments() const
{
   return additionalArgumentsM;
}

}
