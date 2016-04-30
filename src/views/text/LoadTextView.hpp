#ifndef VIEWS_TEXT_LOADTEXTVIEW_HPP_
#define VIEWS_TEXT_LOADTEXTVIEW_HPP_

#include <string>
#include "LoadView.hpp"

namespace Controllers
{
class LoadController;
}

namespace Views
{

class LoadTextView final : public LoadView
{
public:
   LoadTextView();
   ~LoadTextView();

   LoadTextView(const LoadTextView&) = delete;
   LoadTextView& operator=(const LoadTextView&) = delete;

   void interact(Controllers::LoadController* loadController);

private:
   std::string askForName(Controllers::LoadController* loadController);
};

}

#endif
