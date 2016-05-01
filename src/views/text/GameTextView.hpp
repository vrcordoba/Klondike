#ifndef VIEWS_TEXT_GAMETEXTVIEW_HPP_
#define VIEWS_TEXT_GAMETEXTVIEW_HPP_

#include <cstdint>
#include <vector>
#include "GameView.hpp"
#include "CommandTextMenu.hpp"

namespace Controllers
{
class Command;
class GameController;
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

private:
   void showGame(Controllers::GameController* gameController);

   void showWrongCommand() const;
   void buildCommands();
   void showCongratulations() const;

   Controllers::Command* getCommandFromUser();
   Controllers::CommandType captureCommand(
      std::vector<std::uint8_t>& additionalArguments);

   CommandTextMenu commandTextMenuM;
};

}

#endif
