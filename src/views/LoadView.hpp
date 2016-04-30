#ifndef VIEWS_LOADVIEW_HPP_
#define VIEWS_LOADVIEW_HPP_

namespace Controllers
{
class LoadController;
}

namespace Views
{

class LoadView
{
public:
   virtual ~LoadView() {};
   virtual void interact(Controllers::LoadController* loadController) = 0;
};

}

#endif
