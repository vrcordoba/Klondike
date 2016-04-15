
#include "DeckManager.hpp"

#include <cassert>
#include "SpanishDeck.hpp"
#include "FrenchDeck.hpp"
#include "DeckType.hpp"

namespace Models
{

DeckManager::DeckManager() : deckM(nullptr), deckTypeM()
{
}

DeckManager::~DeckManager()
{
   delete deckM;
}

std::vector<std::string> DeckManager::getDeckDescriptions() const
{
   return deckTypeM.getDeckDescriptions();
}

DeckType::Name DeckManager::getDeckType() const
{
   return deckTypeM.getDeckType();
}

Deck* DeckManager::getDeck(std::uint8_t deckType)
{
   switch(deckType)
   {
      case DeckType::SPANISH:
         deckM = new SpanishDeck();
         deckTypeM.setDeckType(DeckType::SPANISH);
         break;
      case DeckType::FRENCH:
         deckM = new FrenchDeck();
         deckTypeM.setDeckType(DeckType::FRENCH);
         break;
      default:
         assert(false);
   }
   return deckM;
}

}
