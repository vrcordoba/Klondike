
#include "DeckManager.hpp"

#include <cassert>
#include "KlondikeConfiguration.hpp"
#include "DeckType.hpp"
#include "SpanishDeck.hpp"
#include "FrenchDeck.hpp"

namespace Models
{

DeckManager::DeckManager() : deckM(nullptr)
{
}

DeckManager::~DeckManager()
{
   delete deckM;
}

Deck* DeckManager::getDeck(std::uint8_t deckType)
{
   if (nullptr != deckM)
      delete deckM;
   switch(deckType)
   {
      case Configuration::DeckType::SPANISH:
         deckM = new SpanishDeck();
         Configuration::KlondikeConfiguration::getInstance().setDeckType(
            Configuration::DeckType::SPANISH);
         break;
      case Configuration::DeckType::FRENCH:
         deckM = new FrenchDeck();
         Configuration::KlondikeConfiguration::getInstance().setDeckType(
            Configuration::DeckType::FRENCH);
         break;
      default:
         assert(false);
   }
   deckM->buildDeck();
   //deckM->shuffle();
   return deckM;
}

}
