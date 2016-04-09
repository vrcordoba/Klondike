#ifndef VIEWS_STARTVIEW_HPP_
#define VIEWS_STARTVIEW_HPP_

namespace Controllers
{
   class StartController;
}

namespace Views
{

class StartView
{
public:
   virtual ~StartView() {};
   virtual void interact(const Controllers::StartController* startController) = 0;
};

}

#endif
