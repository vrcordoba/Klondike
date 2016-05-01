#ifndef VIEWS_TEXT_GAMETEXTVIEW_HPP_
#define VIEWS_TEXT_GAMETEXTVIEW_HPP_

#include <cstdint>
#include <vector>
#include "GameView.hpp"
#include "CommandTextMenu.hpp"
#include "GameControllerVisitor.hpp"

namespace Controllers
{
class Command;
class GameController;
class ManualGameController;
class AutomaticGameController;
}

namespace Views
{

class CommandInterpreter;

class GameTextView final : public GameView, Controllers::GameControllerVisitor
{
public:
   GameTextView();
   ~GameTextView();

   GameTextView(const GameTextView&) = delete;
   GameTextView& operator=(const GameTextView&) = delete;

   void interact(Controllers::GameController* gameController);

   void visit(Controllers::ManualGameController* manualGameController);
   void visit(Controllers::AutomaticGameController* automaticGameController);

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
