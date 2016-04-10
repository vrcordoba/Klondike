#ifndef VIEWS_MOVEVIEW_HPP_
#define VIEWS_MOVEVIEW_HPP_

namespace Controllers
{
   class MoveController;
}

namespace Views
{

class MoveView
{
public:
   virtual ~MoveView() {};
   virtual void interact(Controllers::MoveController* moveController) = 0;
};

}

#endif
