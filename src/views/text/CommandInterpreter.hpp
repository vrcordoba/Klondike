
#ifndef VIEWS_TEXT_COMMANDINTERPRETER_HPP_
#define VIEWS_TEXT_COMMANDINTERPRETER_HPP_

#include <vector>
#include <string>
#include "Command.hpp"

namespace Views
{

class CommandInterpreter final
{
public:
   explicit CommandInterpreter();
   ~CommandInterpreter();

   void setCommand(std::vector<std::string> parsedCommand);
   Controllers::Command getCommand() const;

   bool isWrongNumberOfParameters() const;
   bool isWrongCommand() const;
   bool isHelpCommand() const;

   bool analyzeArguments();

private:
   void interpretTypeOfCommand();
   bool isMoveCommand() const;
   bool analyzeArgumentsOfMovement();
   bool analyzeMultiplePile(const std::string& multiplePileId,
      std::list<std::uint8_t>& additionalArguments);
   bool analyzeNumberOfCardsToMove(std::list<std::uint8_t>& additionalArguments);

   std::vector<std::string> parsedCommandM;
   Controllers::Command commandM;
};

}

#endif
