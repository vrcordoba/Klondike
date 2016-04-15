#ifndef VIEWS_TEXT_STARTTEXTVIEW_HPP_
#define VIEWS_TEXT_STARTTEXTVIEW_HPP_

#include "StartView.hpp"

#include <list>
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

   void interact(Controllers::StartController* startController);

private:
   std::uint8_t getNumPlayers();
   std::uint8_t getNewOrSaveOption(std::uint8_t numPlayers);
   std::uint8_t getTypeOfDeck(std::list<std::string> deckDescriptions);
   Utils::TextMenu buildNewSavedGameMenu();
   Utils::TextMenu buildDeckSelectionMenu(std::list<std::string> deckDescriptions);
};

}

#endif
