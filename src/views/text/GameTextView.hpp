#ifndef VIEWS_TEXT_GAMETEXTVIEW_HPP_
#define VIEWS_TEXT_GAMETEXTVIEW_HPP_

#include <cstdint>
#include <list>
#include <string>
#include "GameView.hpp"
#include "GameController.hpp"

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
   void showWrongCommand() const;
   void showWrongNumberOfParameters() const;
   void showHelp() const;

   std::list<std::string> askForCommand(Controllers::GameController* gameController);
   std::list<std::string> captureCommand() const;
};

}

#endif
