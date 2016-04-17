#ifndef VIEWS_CONTINUEVIEW_HPP_
#define VIEWS_CONTINUEVIEW_HPP_

namespace Controllers
{
class ContinueController;
}

namespace Views
{

class ContinueView
{
public:
   virtual ~ContinueView() {};
   virtual void interact(Controllers::ContinueController* continueController) = 0;
};

}

#endif
