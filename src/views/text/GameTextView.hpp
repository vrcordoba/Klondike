#ifndef VIEWS_TEXT_GAMETEXTVIEW_HPP_
#define VIEWS_TEXT_GAMETEXTVIEW_HPP_

#include <cstdint>
#include <vector>
#include <string>
#include "GameView.hpp"
#include "GameController.hpp"

namespace Controllers
{
class Command;
}

namespace Views
{

class CommandInterpreter;

class GameTextView final : public GameView
{
public:
   GameTextView();
   ~GameTextView();

   GameTextView(const GameTextView&) = delete;
   GameTextView& operator=(const GameTextView&) = delete;

   void interact(Controllers::GameController* gameController);

   void showGame(Controllers::GameController* gameController);

private:
   bool errorOrHelpInCommand(CommandInterpreter& commandInterpreter) const;
   bool analyzeArguments(CommandInterpreter& commandInterpreter) const;
   void showWrongCommand() const;
   void showWrongNumberOfParameters() const;
   void showHelp() const;
   void showCongratulations() const;

   Controllers::Command getCommandFromUser(Controllers::GameController* gameController);
   std::vector<std::string> captureCommand() const;
};

}

#endif
