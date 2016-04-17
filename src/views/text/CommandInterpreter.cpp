
#include "CommandInterpreter.hpp"

#include <cassert>
#include "MovementOriginDestinationType.hpp"

namespace Views
{

CommandInterpreter::CommandInterpreter()
   : parsedCommandM(), commandTypeM()
{
}

CommandInterpreter::~CommandInterpreter()
{
}

void CommandInterpreter::setCommandType(std::vector<std::string> parsedCommand)
{
   parsedCommandM = parsedCommand;
   interpretTypeOfCommand();
}

Controllers::CommandType CommandInterpreter::getCommandType() const
{
   return commandTypeM;
}

std::vector<std::uint8_t> CommandInterpreter::getAdditionalArguments() const
{
   return additionalArgumentsM;
}

void CommandInterpreter::interpretTypeOfCommand()
{
   if (parsedCommandM.size() == 0)
   {
      commandTypeM = Controllers::CommandType::ERROR;
      return;
   }
   std::string order = (*parsedCommandM.begin());
   if ((order == "h") or (order == "help"))
      commandTypeM = Controllers::CommandType::HELP;
   else if ((order == "d") or (order == "draw"))
      commandTypeM = Controllers::CommandType::DRAWCARD;
   else if ((order == "m") or (order == "move"))
      commandTypeM = Controllers::CommandType::MOVE;
   else if ((order == "r") or (order == "restart"))
      commandTypeM = Controllers::CommandType::RESTART;
   else if ((order == "l") or (order == "leave"))
      commandTypeM = Controllers::CommandType::LEAVE;
   else
      commandTypeM = Controllers::CommandType::ERROR;
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
   return (Controllers::CommandType::ERROR == commandTypeM);
}

bool CommandInterpreter::isHelpCommand() const
{
   return (Controllers::CommandType::HELP == commandTypeM);
}

bool CommandInterpreter::analyzeArguments()
{
   if (isMoveCommand())
      return analyzeArgumentsOfMovement();
   return false;
}

bool CommandInterpreter::isMoveCommand() const
{
   return (Controllers::CommandType::MOVE == commandTypeM);
}

bool CommandInterpreter::analyzeArgumentsOfMovement()
{
   additionalArgumentsM.clear();
   if (parsedCommandM.size() < 3)
      return true;
   for (std::uint8_t i = 1; i < 3; ++i)
   {
      if (parsedCommandM[i].size() < 1 or parsedCommandM[i].size() > 2)
         return true;
      if (parsedCommandM[i][0] == 'w')
      {
         additionalArgumentsM.push_back(Controllers::MovementOriginDestinationType::WASTE);
         additionalArgumentsM.push_back(1u);
      }
      else if(parsedCommandM[i][0] == 't' or parsedCommandM[i][0] == 'f')
      {
         if (analyzeMultiplePile(parsedCommandM[i], additionalArgumentsM))
            return true;
      }
      else
         return true;
   }
   if (analyzeNumberOfCardsToMove(additionalArgumentsM))
      return true;
   return false;
}

bool CommandInterpreter::analyzeMultiplePile(const std::string& multiplePileId,
   std::vector<std::uint8_t>& additionalArguments)
{
   if (not std::isdigit(multiplePileId[1]))
      return true;
   if (multiplePileId[0] == 't')
      additionalArguments.push_back(Controllers::MovementOriginDestinationType::TABLEAU);
   else
      additionalArguments.push_back(Controllers::MovementOriginDestinationType::FOUNDATION);
   additionalArguments.push_back(multiplePileId[1] - '0');
   return false;
}

bool CommandInterpreter::analyzeNumberOfCardsToMove(std::vector<std::uint8_t>& additionalArguments)
{
   if (4 == parsedCommandM.size())
   {
      std::uint8_t numCardsToMove;
      try
      {
         numCardsToMove = std::stoi(parsedCommandM[3]);
      }
      catch (const std::exception& e)
      {
         return true;
      }
      additionalArguments.push_back(numCardsToMove);
   }
   else
      additionalArguments.push_back(1);
   return false;
}

}
