
#include "CommandReader.hpp"

#include "IO.hpp"
#include <sstream>
#include <iterator>

namespace Utils
{

CommandReader::CommandReader()
{
}

CommandReader::~CommandReader()
{
}

std::vector<std::string> CommandReader::getCommand(const std::string& message) const
{
   std::string command = IO::getInstance().readString(message);
   return tokenizeCommand(command);
}

std::vector<std::string> CommandReader::tokenizeCommand(const std::string& command) const
{
   std::istringstream iss(command);
   std::vector<std::string> tokenizedCommand{std::istream_iterator<std::string>{iss},
      std::istream_iterator<std::string>{}};
   return tokenizedCommand;
}

}
