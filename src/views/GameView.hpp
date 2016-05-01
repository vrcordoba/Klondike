#ifndef VIEWS_GAMEVIEW_HPP_
#define VIEWS_GAMEVIEW_HPP_

namespace Controllers
{
class GameController;
}

namespace Views
{

class GameView
{
public:
   virtual ~GameView() {};
   virtual void interact(Controllers::GameController* gameController) = 0;
};

}

#endif
