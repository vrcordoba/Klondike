#ifndef VIEWS_TEXT_GAMETEXTVIEW_HPP_
#define VIEWS_TEXT_GAMETEXTVIEW_HPP_

#include <cstdint>
#include <vector>
#include <string>
#include "GameView.hpp"
#include "MoveController.hpp"

namespace Views
{

class GameTextView final : public GameView
{
public:
   GameTextView();
   ~GameTextView();

   GameTextView(const GameTextView&) = delete;
   GameTextView& operator=(const GameTextView&) = delete;

   void interact(Controllers::MoveController* moveController);

   void showGame(Controllers::MoveController* moveController);
   void showHelp() const;

private:
   std::vector<std::string> askForCommand(Controllers::MoveController* moveController);
   std::vector<std::string> captureCommand() const;
   Controllers::MoveController::CommandType typeOfCommand(
      std::vector<std::string> command) const;
   bool isWrongNumberOfParameters(std::vector<std::string> command) const;
   bool isWrongCommand(const Controllers::MoveController::CommandType& commandType) const;
   bool isHelpCommand(const Controllers::MoveController::CommandType& commandType) const;
};

}

#endif
