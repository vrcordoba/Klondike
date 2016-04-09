
#include "DeckBuilder.hpp"

#include <vector>
#include <string>
#include <cassert>
#include "SpanishDeck.hpp"
#include "FrenchDeck.hpp"

namespace Models
{

DeckBuilder::DeckBuilder() : deckTypesDescriptionM()
{
   deckTypesDescriptionM.push_back("Spanish");
   deckTypesDescriptionM.push_back("French");
}

DeckBuilder::~DeckBuilder()
{
}

std::vector<std::string> DeckBuilder::getDecks() const
{
   return deckTypesDescriptionM;
}

Deck* DeckBuilder::build(std::uint8_t deckType)
{
   Deck* deck;
   switch(deckType)
   {
      case SPANISH:
         deck = new SpanishDeck();
         break;
      case FRENCH:
         deck = new FrenchDeck();
         break;
      default:
         assert(false);
   }
   return deck;
}

}
