
#include "CommandTextMenu.hpp"

#include <sstream>
#include <iterator>

namespace Views
{

CommandTextMenu::CommandTextMenu(const std::string& title) : titleM(title +
   " (For a list of the available commands, type h)"),
   ioM(Utils::IO::getInstance()), commandInterpreterM()
{
   commandInterpreterM.addCommand("h", " - Shows this help.", Controllers::CommandType::HELP);
}

CommandTextMenu::~CommandTextMenu()
{
}

void CommandTextMenu::addCommand(const std::string& commandId, const std::string& commandHelp,
   Controllers::CommandType commandType)
{
   commandInterpreterM.addCommand(commandId, commandHelp, commandType);
}

Controllers::CommandType CommandTextMenu::getCommand()
{
   do
   {
      std::string command = ioM.readString(titleM);
      std::vector<std::string> tokenizedCommand = tokenizeCommand(command);
      commandInterpreterM.setCommandType(tokenizedCommand);
   } while (errorOrHelpInCommand() or analyzeArguments());
   return commandInterpreterM.getCommandType();
}

bool CommandTextMenu::errorOrHelpInCommand() const
{
   if (commandInterpreterM.isWrongNumberOfParameters())
      showWrongNumberOfParameters();
   else if (commandInterpreterM.isWrongCommand())
      showWrongCommand();
   else if (commandInterpreterM.isHelpCommand())
      showHelp();
   else
      return false;
   return true;
}

bool CommandTextMenu::analyzeArguments()
{
   if (commandInterpreterM.analyzeArguments())
   {
      showWrongCommand();
      return true;
   }
   return false;
}

void CommandTextMenu::showWrongNumberOfParameters() const
{
   ioM.writeString("Wrong number of parameters.");
}

void CommandTextMenu::showWrongCommand() const
{
   ioM.writeString("Wrong command.");
}

void CommandTextMenu::showHelp() const
{
   ioM.writeString("These are the available commands:");
   for (auto command : commandInterpreterM.getAvailableCommands())
      ioM.writeString(command);
}

std::vector<std::uint8_t> CommandTextMenu::getAdditionalArguments() const
{
   return commandInterpreterM.getAdditionalArguments();
}

std::vector<std::string> CommandTextMenu::tokenizeCommand(const std::string& command) const
{
   std::istringstream iss(command);
   std::vector<std::string> tokenizedCommand{std::istream_iterator<std::string>{iss},
      std::istream_iterator<std::string>{}};
   return tokenizedCommand;
}

}
