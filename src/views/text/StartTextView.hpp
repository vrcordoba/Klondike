#ifndef VIEWS_TEXT_STARTTEXTVIEW_HPP_
#define VIEWS_TEXT_STARTTEXTVIEW_HPP_

#include "StartView.hpp"

#include <vector>
#include <string>
#include "TextMenu.hpp"

namespace Controllers
{
   class StartController;
}

namespace Views
{

class StartTextView final : public StartView
{
public:
   StartTextView();
   ~StartTextView();

   StartTextView(const StartTextView&) = delete;
   StartTextView& operator=(const StartTextView&) = delete;

   void interact(const Controllers::StartController* startController);

private:
   Utils::TextMenu buildNewSavedGameMenu();
   Utils::TextMenu buildDeckSelectionMenu(std::vector<std::string> decks);
};

}

#endif
