
#include "StartTextView.hpp"

#include <cstdint>
#include <cassert>
#include "LimitedIntDialog.hpp"
#include "TextMenu.hpp"
#include "StartController.hpp"
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
   std::uint8_t newOrSavedOption = 1; //getNewOrSaveOption(numPlayers);
   std::uint8_t typeDeck = getTypeOfDeck(
      Configuration::KlondikeConfiguration::getInstance().getDeckDescriptions());
   startController->start(numPlayers, newOrSavedOption, typeDeck);
}

std::uint8_t StartTextView::getNumPlayers()
{
   return Utils::LimitedIntDialog("How many players?", 0, 1).read();
}

std::uint8_t StartTextView::getNewOrSaveOption(std::uint8_t numPlayers)
{
   std::uint8_t newOrSavedOption = 1;
   if (1 == numPlayers)
   {
      Utils::TextMenu newSavedMenu = buildNewSavedGameMenu();
      newSavedMenu.show();
      newOrSavedOption = newSavedMenu.read();
   }
   return newOrSavedOption;
}

Utils::TextMenu StartTextView::buildNewSavedGameMenu()
{
   Utils::TextMenu menu("Do you want to play a new or a saved game?");
   menu.addOption("New game");
   menu.addOption("Saved game");
   return menu;
}

std::uint8_t StartTextView::getTypeOfDeck(std::list<std::string> deckDescriptions)
{
   Utils::TextMenu newSavedMenu = buildDeckSelectionMenu(deckDescriptions);
   newSavedMenu.show();
   return newSavedMenu.read();
}

Utils::TextMenu StartTextView::buildDeckSelectionMenu(std::list<std::string> deckDescriptions)
{
   assert(deckDescriptions.size() > 0);
   std::string menuTitle = "Do you want to play with ";
   std::list<std::string>::const_iterator itDeckDescriptions = deckDescriptions.begin();
   for (std::uint8_t i = 0; i < deckDescriptions.size() - 1; ++i, ++itDeckDescriptions)
   {
      menuTitle += (*itDeckDescriptions) + "/";
   }
   menuTitle += (*itDeckDescriptions) + " deck?";
   Utils::TextMenu menu(menuTitle);
   for (std::string deck : deckDescriptions)
   {
      menu.addOption(deck + " deck");
   }
   return menu;
}

}
