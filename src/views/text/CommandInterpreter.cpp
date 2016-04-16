
#include "CommandInterpreter.hpp"

#include <cassert>
#include "MovementOriginDestinationType.hpp"

namespace Views
{

CommandInterpreter::CommandInterpreter()
   : parsedCommandM(), commandM()
{
}

CommandInterpreter::~CommandInterpreter()
{
}

void CommandInterpreter::setCommand(std::vector<std::string> parsedCommand)
{
   parsedCommandM = parsedCommand;
   interpretTypeOfCommand();
}

Controllers::Command CommandInterpreter::getCommand() const
{
   return commandM;
}

void CommandInterpreter::interpretTypeOfCommand()
{
   if (parsedCommandM.size() == 0)
   {
      commandM.setCommandType(Controllers::CommandType::ERROR);
      return;
   }
   std::string order = (*parsedCommandM.begin());
   if ((order == "h") or (order == "help"))
      commandM.setCommandType(Controllers::CommandType::HELP);
   else if ((order == "d") or (order == "draw"))
      commandM.setCommandType(Controllers::CommandType::DRAWCARD);
   else if ((order == "m") or (order == "move"))
      commandM.setCommandType(Controllers::CommandType::MOVE);
   else
      commandM.setCommandType(Controllers::CommandType::ERROR);
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
   return (Controllers::CommandType::ERROR == commandM.getCommandType());
}

bool CommandInterpreter::isHelpCommand() const
{
   return (Controllers::CommandType::HELP == commandM.getCommandType());
}

bool CommandInterpreter::analyzeArguments()
{
   if (isMoveCommand())
   {
      return analyzeArgumentsOfMovement();
   }
   return false;
}

bool CommandInterpreter::isMoveCommand() const
{
   return (Controllers::CommandType::MOVE == commandM.getCommandType());
}

bool CommandInterpreter::analyzeArgumentsOfMovement()
{
   if (parsedCommandM.size() < 3)
      return true;
   std::list<std::uint8_t> additionalArguments;
   for (std::uint8_t i = 1; i < 3; ++i)
   {
      if (parsedCommandM[i].size() < 1 or parsedCommandM[i].size() > 2)
         return true;
      if (parsedCommandM[i][0] == 'w')
         additionalArguments.push_back(Controllers::MovementOriginDestinationType::WASTE);
      else if(parsedCommandM[i][0] == 't' or parsedCommandM[i][0] == 'f')
      {
         if (analyzeMultiplePile(parsedCommandM[i], additionalArguments))
            return true;
      }
      else
         return true;
   }
   if (analyzeNumberOfCardsToMove(additionalArguments))
   {
      return true;
   }
   commandM.setAdditionalArguments(additionalArguments);
   return false;
}

bool CommandInterpreter::analyzeMultiplePile(const std::string& multiplePileId,
   std::list<std::uint8_t>& additionalArguments)
{
   if (not std::isdigit(multiplePileId[1]))
      return true;
   if (multiplePileId[0] == 't')
   {
      additionalArguments.push_back(Controllers::MovementOriginDestinationType::TABLEAU);
   }
   else
   {
      additionalArguments.push_back(Controllers::MovementOriginDestinationType::FOUNDATION);
   }
   additionalArguments.push_back(multiplePileId[1]);
   return false;
}

bool CommandInterpreter::analyzeNumberOfCardsToMove(std::list<std::uint8_t>& additionalArguments)
{
   if (4 == parsedCommandM.size())
   {
      std::uint8_t numCardsToMove;
      try
      {
         numCardsToMove = std::stoi(parsedCommandM[3]);
      }
      catch (std::exception& e)
      {
         return true;
      }
      additionalArguments.push_back(numCardsToMove);
   }
   else
   {
      additionalArguments.push_back(1);
   }
   return false;
}

}
