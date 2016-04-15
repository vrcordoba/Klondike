
#include "CommandInterpreter.hpp"

#include <cassert>

namespace Views
{

CommandInterpreter::CommandInterpreter()
   : parsedCommandM(), commandTypeM(Controllers::GameController::CommandType::ERROR)
{
}

CommandInterpreter::~CommandInterpreter()
{
}

void CommandInterpreter::setCommand(std::list<std::string> parsedCommand)
{
   parsedCommandM = parsedCommand;
}

void CommandInterpreter::interpretTypeOfCommand()
{
   assert(parsedCommandM.size() > 0);
   std::string order = (*parsedCommandM.begin());
   if ((order == "h") or (order == "help"))
      commandTypeM = Controllers::GameController::CommandType::HELP;
   else if ((order == "d") or (order == "draw"))
      commandTypeM = Controllers::GameController::CommandType::DRAWCARD;
   else if ((order == "m") or (order == "move"))
      commandTypeM = Controllers::GameController::CommandType::MOVE;
   else
      commandTypeM = Controllers::GameController::CommandType::ERROR;
}

Controllers::GameController::CommandType CommandInterpreter::getTypeOfCommand() const
{
   return commandTypeM;
}

bool CommandInterpreter::isWrongNumberOfParameters() const
{
   bool errorInCommand = false;
   errorInCommand |= (parsedCommandM.size() == 0);
   errorInCommand |= (parsedCommandM.size() > 4);
   return errorInCommand;
}

bool CommandInterpreter::isWrongCommand() const
{
   bool isWrongCommand = (Controllers::GameController::CommandType::ERROR == commandTypeM);
   return isWrongCommand;
}

bool CommandInterpreter::isHelpCommand() const
{
   bool isHelpCommand = (Controllers::GameController::CommandType::HELP == commandTypeM);
   return isHelpCommand;
}

}
