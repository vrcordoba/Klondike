
#include "DeckBuilder.hpp"

#include <cassert>
#include "SpanishDeck.hpp"
#include "FrenchDeck.hpp"
#include "DeckType.hpp"

namespace Models
{

DeckBuilder::DeckBuilder() : deckM(nullptr), deckTypeM()
{
}

DeckBuilder::~DeckBuilder()
{
   delete deckM;
}

std::vector<std::string> DeckBuilder::getDecks() const
{
   return deckTypeM.getDecks();
}

DeckType::Name DeckBuilder::getDeckType() const
{
   return deckTypeM.getDeckType();
}

Deck* DeckBuilder::build(std::uint8_t deckType)
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
