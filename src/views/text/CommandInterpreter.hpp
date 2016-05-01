#ifndef VIEWS_TEXT_COMMANDINTERPRETER_HPP_
#define VIEWS_TEXT_COMMANDINTERPRETER_HPP_

#include <vector>
#include <map>
#include <string>
#include <cstdint>
#include "CommandType.hpp"

namespace Views
{

class CommandInterpreter final
{
public:
   CommandInterpreter();
   ~CommandInterpreter();

   CommandInterpreter(const CommandInterpreter&) = delete;
   CommandInterpreter& operator=(const CommandInterpreter&) = delete;

   void setCommandType(std::vector<std::string> parsedCommand);
   Controllers::CommandType getCommandType() const;
   std::vector<std::uint8_t> getAdditionalArguments() const;

   bool isWrongNumberOfParameters() const;
   bool isWrongCommand() const;
   bool isHelpCommand() const;

   bool analyzeArguments();

   void addCommand(const std::string& commandId, const std::string& commandHelp,
      Controllers::CommandType commandType);

   std::vector<std::string> getAvailableCommands() const;

private:
   void interpretTypeOfCommand();
   bool isMoveCommand() const;
   bool analyzeArgumentsOfMovement();
   bool analyzeMultiplePile(const std::string& multiplePileId);
   bool analyzeNumberOfCardsToMove();

   std::vector<std::string> parsedCommandM;
   Controllers::CommandType commandTypeM;
   std::vector<std::uint8_t> additionalArgumentsM;
   std::map<const std::string, std::pair<const std::string,
      Controllers::CommandType>> commandDictionaryM;
};

}

#endif
