#ifndef VIEWS_TEXT_SAVETEXTVIEW_HPP_
#define VIEWS_TEXT_SAVETEXTVIEW_HPP_

#include <string>

namespace Controllers
{
class SaveController;
}

namespace Views
{

class SaveTextView
{
public:
   SaveTextView();
   ~SaveTextView();

   void interact(Controllers::SaveController* saveController);

private:
   void askForName(Controllers::SaveController* saveController);

   std::string saveFileNameM;
};

}

#endif
