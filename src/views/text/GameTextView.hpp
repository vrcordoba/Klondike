#ifndef VIEWS_TEXT_GAMETEXTVIEW_HPP_
#define VIEWS_TEXT_GAMETEXTVIEW_HPP_

#include "GameView.hpp"
#include "TextMenu.hpp"

namespace Controllers
{
   class MoveController;
}

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

private:
   void buildMenu();
   void showGame(Controllers::MoveController* moveController) const;
   Utils::TextMenu menuM;
};

}

#endif
