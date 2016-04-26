
#ifndef VIEWS_TEXT_COMMANDINTERPRETER_HPP_
#define VIEWS_TEXT_COMMANDINTERPRETER_HPP_

#include <vector>
#include <string>
#include <cstdint>
#include "Command.hpp"
#include "CommandType.hpp"

namespace Views
{

class CommandInterpreter final
{
public:
   explicit CommandInterpreter();
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

private:
   void interpretTypeOfCommand();
   bool isMoveCommand() const;
   bool analyzeArgumentsOfMovement();
   bool analyzeMultiplePile(const std::string& multiplePileId);
   bool analyzeNumberOfCardsToMove();

   std::vector<std::string> parsedCommandM;
   Controllers::CommandType commandTypeM;
   std::vector<std::uint8_t> additionalArgumentsM;
};

}

#endif
