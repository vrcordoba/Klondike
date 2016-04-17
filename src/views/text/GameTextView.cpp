
#include "GameTextView.hpp"

#include "CardTableTextView.hpp"
#include "CommandReader.hpp"
#include "IO.hpp"
#include "CommandInterpreter.hpp"
#include "Command.hpp"
#include "CommandManager.hpp"

namespace Views
{

GameTextView::GameTextView()
{
}

GameTextView::~GameTextView()
{
}

void GameTextView::interact(Controllers::GameController* gameController)
{
   Controllers::Command* command = getCommandFromUser(gameController);
   if (gameController->isValidCommand(command))
      gameController->applyCommand(command);
   else
      showWrongCommand();
   if (gameController->isGameWon())
   {
      showCongratulations();
   }
}

Controllers::Command* GameTextView::getCommandFromUser(
   Controllers::GameController* gameController)
{
   showGame(gameController);
   std::vector<std::string> command;
   CommandInterpreter commandInterpreter;
   do
   {
      command = captureCommand();
      commandInterpreter.setCommandType(command);
   } while (errorOrHelpInCommand(commandInterpreter) or
      analyzeArguments(commandInterpreter));
   Controllers::CommandType commandType = commandInterpreter.getCommandType();
   std::vector<std::uint8_t> additionalArguments = commandInterpreter.getAdditionalArguments();
   return Controllers::CommandManager().getCommand(commandType, additionalArguments);
}

bool GameTextView::errorOrHelpInCommand(CommandInterpreter& commandInterpreter) const
{
   if (commandInterpreter.isWrongNumberOfParameters())
   {
      showWrongNumberOfParameters();
      return true;
   }
   if (commandInterpreter.isWrongCommand())
   {
      showWrongCommand();
      return true;
   }
   if (commandInterpreter.isHelpCommand())
   {
      showHelp();
      return true;
   }
   return false;
}

bool GameTextView::analyzeArguments(CommandInterpreter& commandInterpreter) const
{
   if (commandInterpreter.analyzeArguments())
   {
      showWrongCommand();
      return true;
   }
   return false;
}

void GameTextView::showGame(Controllers::GameController* gameController)
{
   CardTableTextView cardTableTextView(gameController->getCardTableController());
   cardTableTextView.show();
}

std::vector<std::string> GameTextView::captureCommand() const
{
   Utils::CommandReader commandReader;
   return commandReader.getCommand("Please, introduce the command (For a list "
      "of the available commands, type h/help)");
}

void GameTextView::showWrongCommand() const
{
   Utils::IO::getInstance().writeString("Wrong command.");
}

void GameTextView::showWrongNumberOfParameters() const
{
   Utils::IO::getInstance().writeString("Wrong number of parameters.");
}

void GameTextView::showHelp() const
{
   Utils::IO& io = Utils::IO::getInstance();
   io.writeString("These are the available commands:");
   io.writeString("h/help - Shows this help.");
   io.writeString("m/move <origin> <destination> <num_cards> - Move \"num_cards\" cards "
      "from origin (w/t1/t2/t3/...) to destination (f1/f2/f3/f4/t1/t2/t3/...). If "
      "\"num_cards\" is not specified only one card is moved.");
   io.writeString("d/draw - Draw card from deck to waste.");
}

void GameTextView::showCongratulations() const
{
   Utils::IO& io = Utils::IO::getInstance();
   io.writeString("=================================================");
   io.writeString("========= Congratulations! You have won =========");
   io.writeString("=================================================");
}

}
