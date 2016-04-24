#ifndef VIEWS_SAVEVIEW_HPP_
#define VIEWS_SAVEVIEW_HPP_

namespace Controllers
{
class SaveController;
}

namespace Views
{

class SaveView
{
public:
   virtual ~SaveView() {};
   virtual void interact(Controllers::SaveController* saveController) = 0;
};

}

#endif
