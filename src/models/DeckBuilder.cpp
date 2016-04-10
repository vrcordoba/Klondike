
#include "DeckBuilder.hpp"

#include <cassert>
#include "SpanishDeck.hpp"
#include "FrenchDeck.hpp"

namespace Models
{

DeckBuilder::DeckBuilder() : deckTypesDescriptionM(), deckM(nullptr)
{
   deckTypesDescriptionM.push_back("Spanish");
   deckTypesDescriptionM.push_back("French");
}

DeckBuilder::~DeckBuilder()
{
   delete deckM;
}

std::vector<std::string> DeckBuilder::getDecks() const
{
   return deckTypesDescriptionM;
}

Deck* DeckBuilder::build(std::uint8_t deckType)
{
   switch(deckType)
   {
      case SPANISH:
         deckM = new SpanishDeck();
         break;
      case FRENCH:
         deckM = new FrenchDeck();
         break;
      default:
         assert(false);
   }
   return deckM;
}

}
