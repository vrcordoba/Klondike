
#include "GameTextView.hpp"

#include "MoveController.hpp"
#include "CardTableTextView.hpp"

namespace Views
{

GameTextView::GameTextView() : menuM("What is your next move?")
{
   buildMenu();
}

GameTextView::~GameTextView()
{
}

void GameTextView::buildMenu()
{
   menuM.addOption("Move from deck to waste");
   menuM.addOption("Move from waste to foundations");
   menuM.addOption("Move from waste to tableaus");
   menuM.addOption("Move from tableau to tableau");
   menuM.addOption("Move from tableau to foundation");
   menuM.addOption("Undo movement");
   menuM.addOption("Save game");
   menuM.addOption("Begin a new game");
   menuM.addOption("Leave game");
}

void GameTextView::interact(Controllers::MoveController* moveController)
{
   showGame(moveController);
   menuM.show();
   menuM.read();
   moveController->move();
}

void GameTextView::showGame(Controllers::MoveController* moveController) const
{
   CardTableTextView cardTableTextView(moveController->getCardTableController());
   cardTableTextView.show();
}

}
