
#include "CommandInterpreter.hpp"

#include "PileType.hpp"

namespace Views
{

CommandInterpreter::CommandInterpreter() : parsedCommandM(), commandTypeM(),
   additionalArgumentsM(), commandDictionaryM()
{
}

CommandInterpreter::~CommandInterpreter()
{
}

void CommandInterpreter::addCommand(const std::string& commandId, const std::string& commandHelp,
   Controllers::CommandType commandType)
{
   commandDictionaryM.emplace(commandId, std::make_pair(commandHelp, commandType));
}

void CommandInterpreter::setCommandType(std::vector<std::string> parsedCommand)
{
   parsedCommandM = parsedCommand;
   interpretTypeOfCommand();
}

void CommandInterpreter::interpretTypeOfCommand()
{
   std::map<const std::string, std::pair<const std::string,
      Controllers::CommandType>>::const_iterator commandIt =
      commandDictionaryM.find(parsedCommandM[0]);
   if (commandIt == commandDictionaryM.end())
      commandTypeM = Controllers::CommandType::ERROR;
   else
      commandTypeM = commandIt->second.second;
}

Controllers::CommandType CommandInterpreter::getCommandType() const
{
   return commandTypeM;
}

std::vector<std::uint8_t> CommandInterpreter::getAdditionalArguments() const
{
   return additionalArgumentsM;
}

std::vector<std::string> CommandInterpreter::getAvailableCommands() const
{
   std::vector<std::string> availableCommands;
   for (auto command : commandDictionaryM)
   {
      availableCommands.push_back(command.first + command.second.first);
   }
   return availableCommands;
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
         additionalArgumentsM.push_back(Models::PileType::WASTE);
         additionalArgumentsM.push_back(1u);
      }
      else if(parsedCommandM[i][0] == 't' or parsedCommandM[i][0] == 'f')
      {
         if (analyzeMultiplePile(parsedCommandM[i]))
            return true;
      }
      else
         return true;
   }
   if (analyzeNumberOfCardsToMove())
      return true;
   return false;
}

bool CommandInterpreter::analyzeMultiplePile(const std::string& multiplePileId)
{
   if (not std::isdigit(multiplePileId[1]))
      return true;
   if (multiplePileId[0] == 't')
      additionalArgumentsM.push_back(Models::PileType::TABLEAU);
   else
      additionalArgumentsM.push_back(Models::PileType::FOUNDATION);
   additionalArgumentsM.push_back(multiplePileId[1] - '0');
   return false;
}

bool CommandInterpreter::analyzeNumberOfCardsToMove()
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
      additionalArgumentsM.push_back(numCardsToMove);
   }
   else
      additionalArgumentsM.push_back(1);
   return false;
}

}
