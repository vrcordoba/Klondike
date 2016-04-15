
#include "StartTextView.hpp"

#include <cstdint>
#include <cassert>
#include "LimitedIntDialog.hpp"
#include "TextMenu.hpp"
#include "StartController.hpp"

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
   std::uint8_t typeDeck = getTypeOfDeck(startController->getDeckDescriptions());
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

std::uint8_t StartTextView::getTypeOfDeck(std::vector<std::string> decks)
{
   Utils::TextMenu newSavedMenu = buildDeckSelectionMenu(decks);
   newSavedMenu.show();
   return newSavedMenu.read();
}

Utils::TextMenu StartTextView::buildDeckSelectionMenu(std::vector<std::string> decks)
{
   assert(decks.size() > 0);
   std::string menuTitle = "Do you want to play with ";
   std::uint8_t i = 0;
   for (; i < decks.size() - 1; ++i)
   {
      menuTitle += decks[i] + "/";
   }
   menuTitle += decks[i] + " deck?";
   Utils::TextMenu menu(menuTitle);
   for (std::string deck : decks)
   {
      menu.addOption(deck + " deck");
   }
   return menu;
}

}
