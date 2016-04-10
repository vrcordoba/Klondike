
#include "StartTextView.hpp"

#include <cstdint>
#include <cassert>
#include "IO.hpp"
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
   Utils::IO io;
   io.writeString("Welcome to Klondike game");
   std::uint8_t numPlayers = Utils::LimitedIntDialog("How many players?", 0, 1).read();
   std::uint8_t newOrSavedOption = 1;
   if (1 == numPlayers)
   {
      Utils::TextMenu newSavedMenu = buildNewSavedGameMenu();
      newSavedMenu.show();
      newOrSavedOption = newSavedMenu.read();
   }
   Utils::TextMenu newSavedMenu = buildDeckSelectionMenu(startController->getDecks());
   newSavedMenu.show();
   std::uint8_t typeDeck = newSavedMenu.read();
   startController->start(numPlayers, newOrSavedOption, typeDeck);
}

Utils::TextMenu StartTextView::buildNewSavedGameMenu()
{
   Utils::TextMenu menu("Do you want to play a new or a saved game?");
   menu.addOption("New game");
   menu.addOption("Saved game");
   return menu;
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
