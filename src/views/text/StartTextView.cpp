
#include "StartTextView.hpp"

#include <cstdint>
#include <cassert>
#include "LimitedIntDialog.hpp"
#include "KlondikeConfiguration.hpp"

namespace Views
{

StartTextView::StartTextView()
{
}

StartTextView::~StartTextView()
{
}

void StartTextView::interact(Controllers::StartController* startController)
{
   std::uint8_t numPlayers = 1; //getNumPlayers();
   Controllers::StartController::GameType newOrSavedOption =
      Controllers::StartController::GameType::NEW;
   Configuration::DeckType::Type typeDeck = Configuration::DeckType::Type::UNKNOWN;
   if (1 == numPlayers)
   {
      newOrSavedOption = getNewOrSaveOption();
      if (Controllers::StartController::GameType::NEW == newOrSavedOption)
         typeDeck = getTypeOfDeck(
            Configuration::KlondikeConfiguration::getInstance().getDeckDescriptions());
   }
   startController->start(numPlayers, newOrSavedOption, typeDeck);
}

std::uint8_t StartTextView::getNumPlayers()
{
   return Utils::LimitedIntDialog("How many players?", 0, 1).read();
}

Controllers::StartController::GameType StartTextView::getNewOrSaveOption()
{
   Utils::NumericTextMenu newSavedMenu = buildNewSavedGameMenu();
   newSavedMenu.show();
   return static_cast<Controllers::StartController::GameType>(newSavedMenu.read());
}

Utils::NumericTextMenu StartTextView::buildNewSavedGameMenu()
{
   Utils::NumericTextMenu menu("Do you want to play a new or a saved game?");
   menu.addOption("New game");
   menu.addOption("Saved game");
   return menu;
}

Configuration::DeckType::Type StartTextView::getTypeOfDeck(std::list<std::string> deckDescriptions)
{
   Utils::NumericTextMenu typeOfDeckMenu = buildDeckSelectionMenu(deckDescriptions);
   typeOfDeckMenu.show();
   return static_cast<Configuration::DeckType::Type>(typeOfDeckMenu.read());
}

Utils::NumericTextMenu StartTextView::buildDeckSelectionMenu(std::list<std::string> deckDescriptions)
{
   assert(not deckDescriptions.empty());
   std::string menuTitle = "Do you want to play with ";
   std::list<std::string>::const_iterator itDeckDescriptions = deckDescriptions.begin();
   for (std::uint8_t i = 0; i < deckDescriptions.size() - 1; ++i, ++itDeckDescriptions)
   {
      menuTitle += (*itDeckDescriptions) + "/";
   }
   menuTitle += (*itDeckDescriptions) + " deck?";
   Utils::NumericTextMenu menu(menuTitle);
   for (auto deck : deckDescriptions)
   {
      menu.addOption(deck + " deck");
   }
   return menu;
}

}
