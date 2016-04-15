
#include "GameTextView.hpp"

#include <cassert>
#include "CardTableTextView.hpp"
#include "CommandReader.hpp"
#include "IO.hpp"

namespace Views
{

GameTextView::GameTextView()
{
}

GameTextView::~GameTextView()
{
}

void GameTextView::interact(Controllers::MoveController* moveController)
{
   std::vector<std::string> command = askForCommand(moveController);
   moveController->move();
}

// TODO: Return a parsed command
std::vector<std::string> GameTextView::askForCommand(
   Controllers::MoveController* moveController)
{
   showGame(moveController);
   std::vector<std::string> command;
   Controllers::MoveController::CommandType commandType;
   bool wrongNumberOfParameters;
   do
   {
      command = captureCommand();
      wrongNumberOfParameters = isWrongNumberOfParameters(command);
      if (not wrongNumberOfParameters)
      {
         commandType = typeOfCommand(command);
      }
   } while (wrongNumberOfParameters or isWrongCommand(commandType)
      or isHelpCommand(commandType));
   return command;
}

void GameTextView::showGame(Controllers::MoveController* moveController)
{
   CardTableTextView cardTableTextView(moveController->getCardTableController());
   cardTableTextView.show();
}

std::vector<std::string> GameTextView::captureCommand() const
{
   Utils::CommandReader commandReader;
   return commandReader.getCommand("Please, introduce the command (For a list "
      "of the available commands, type h/help)");
}

Controllers::MoveController::CommandType GameTextView::typeOfCommand(
   std::vector<std::string> command) const
{
   assert(command.size() > 0);
   Controllers::MoveController::CommandType commandType;
   std::string order = command[0];
   if ((order == "h") or (order == "help"))
      commandType = Controllers::MoveController::CommandType::HELP;
   else if ((order == "d") or (order == "draw"))
      commandType = Controllers::MoveController::CommandType::DRAWCARD;
   else if ((order == "m") or (order == "move"))
      commandType = Controllers::MoveController::CommandType::MOVE;
   else
      commandType = Controllers::MoveController::CommandType::ERROR;
   return commandType;
}

bool GameTextView::isWrongNumberOfParameters(std::vector<std::string> command) const
{
   bool errorInCommand = false;
   errorInCommand |= (command.size() == 0);
   errorInCommand |= (command.size() > 4);
   if (errorInCommand)
   {
      Utils::IO::getInstance().writeString("Wrong number of parameters.");
   }
   return errorInCommand;
}

bool GameTextView::isWrongCommand(const Controllers::MoveController::CommandType& commandType) const
{
   bool isWrongCommand = (Controllers::MoveController::CommandType::ERROR == commandType);
   if (isWrongCommand)
   {
      Utils::IO::getInstance().writeString("Wrong command.");
   }
   return isWrongCommand;
}

bool GameTextView::isHelpCommand(const Controllers::MoveController::CommandType& commandType) const
{
   bool isHelpCommand = (Controllers::MoveController::CommandType::HELP == commandType);
   if (isHelpCommand)
   {
      showHelp();
   }
   return isHelpCommand;
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

}
