
#include "DeckPrototyper.hpp"

#include <cassert>
#include "SpanishDeck.hpp"
#include "FrenchDeck.hpp"

namespace Models
{

DeckPrototyper::DeckPrototyper()
{
   deckPrototypesM[Configuration::DeckType::Type::SPANISH] = new SpanishDeck();
   deckPrototypesM[Configuration::DeckType::Type::FRENCH] = new FrenchDeck();
}

DeckPrototyper::~DeckPrototyper()
{
}

Deck* DeckPrototyper::getDeck(Configuration::DeckType::Type deckType)
{
   std::map<Configuration::DeckType::Type, Deck*>::const_iterator deckIt =
      deckPrototypesM.find(deckType);
   assert(deckIt != deckPrototypesM.end());
   Deck* deck = deckIt->second->clone();
   deck->buildDeck();
   return deck;
}

}
