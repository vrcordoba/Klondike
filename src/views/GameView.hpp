#ifndef VIEWS_GAMEVIEW_HPP_
#define VIEWS_GAMEVIEW_HPP_

namespace Controllers
{
   class MoveController;
}

namespace Views
{

class GameView
{
public:
   virtual ~GameView() {};
   virtual void interact(Controllers::MoveController* moveController) = 0;

   virtual void showGame(Controllers::MoveController* moveController) = 0;
   virtual void showHelp() const = 0;
};

}

#endif
