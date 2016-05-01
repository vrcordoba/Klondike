
#include "GameTextView.hpp"

#include "CardTableTextView.hpp"
#include "GameController.hpp"
#include "Command.hpp"
#include "CommandPrototyper.hpp"
#include "IO.hpp"

namespace Views
{

GameTextView::GameTextView() : commandTextMenuM("Please, introduce the command")
{
   buildCommands();
}

GameTextView::~GameTextView()
{
}

void GameTextView::buildCommands()
{
   commandTextMenuM.addCommand("m", " <origin> <destination> <num_cards> - Move "
      "\"num_cards\" cards from origin (w/t1/t2/t3/...) to destination "
      "(f1/f2/f3/f4/t1/t2/t3/...). If \"num_cards\" is not specified only"
      " one card is moved.", Controllers::CommandType::MOVE);
   commandTextMenuM.addCommand("d", " - Draw card from deck to waste.",
      Controllers::CommandType::DRAWCARD);
   commandTextMenuM.addCommand("s", " - Save current game", Controllers::CommandType::SAVE);
   commandTextMenuM.addCommand("u", " - Undo last movement.", Controllers::CommandType::UNDO);
   commandTextMenuM.addCommand("r", " - Redo last movement.", Controllers::CommandType::REDO);
   commandTextMenuM.addCommand("i", " - Init game.", Controllers::CommandType::INIT);
   commandTextMenuM.addCommand("l", " - Leave game.", Controllers::CommandType::LEAVE);
}

void GameTextView::interact(Controllers::GameController* gameController)
{
   showGame(gameController);
   Controllers::Command* command = getCommandFromUser();
   if (gameController->isValidCommand(command))
      gameController->applyCommand(command);
   else
      showWrongCommand();
   if (gameController->isGameWon())
   {
      showGame(gameController);
      showCongratulations();
   }
   delete command;
}

void GameTextView::showGame(Controllers::GameController* gameController)
{
   CardTableTextView cardTableTextView(gameController->getCardTableController());
   cardTableTextView.show();
}

Controllers::Command* GameTextView::getCommandFromUser()
{
   std::vector<std::uint8_t> additionalArguments;
   Controllers::CommandType commandType = captureCommand(additionalArguments);
   return Controllers::CommandPrototyper().getCommand(commandType, additionalArguments);
}

Controllers::CommandType GameTextView::captureCommand(std::vector<std::uint8_t>& additionalArguments)
{
   Controllers::CommandType commandType = commandTextMenuM.getCommand();
   additionalArguments = commandTextMenuM.getAdditionalArguments();
   return commandType;
}

void GameTextView::showWrongCommand() const
{
   commandTextMenuM.showWrongCommand();
}

void GameTextView::showCongratulations() const
{
   Utils::IO& io = Utils::IO::getInstance();
   io.writeString("=================================================");
   io.writeString("========= Congratulations! You have won =========");
   io.writeString("=================================================");
}

}
