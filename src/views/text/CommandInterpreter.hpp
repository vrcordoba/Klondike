
#ifndef VIEWS_TEXT_COMMANDINTERPRETER_HPP_
#define VIEWS_TEXT_COMMANDINTERPRETER_HPP_

#include <list>
#include <string>
#include "GameController.hpp"

namespace Views
{

class CommandInterpreter final
{
public:
   explicit CommandInterpreter();
   ~CommandInterpreter();

   void setCommand(std::list<std::string> parsedCommand);

   Controllers::GameController::CommandType getTypeOfCommand() const;

   bool isWrongNumberOfParameters() const;
   bool isWrongCommand() const;
   bool isHelpCommand() const;

   void interpretTypeOfCommand();

private:

   std::list<std::string> parsedCommandM;
   Controllers::GameController::CommandType commandTypeM;
};

}

#endif
