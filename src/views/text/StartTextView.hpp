#ifndef VIEWS_TEXT_STARTTEXTVIEW_HPP_
#define VIEWS_TEXT_STARTTEXTVIEW_HPP_

#include "StartView.hpp"

#include <list>
#include <string>
#include "TextMenu.hpp"
#include "DeckType.hpp"
#include "StartController.hpp"

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
   Controllers::StartController::GameType getNewOrSaveOption();
   Configuration::DeckType::Type getTypeOfDeck(std::list<std::string> deckDescriptions);
   Utils::TextMenu buildNewSavedGameMenu();
   Utils::TextMenu buildDeckSelectionMenu(std::list<std::string> deckDescriptions);
};

}

#endif
