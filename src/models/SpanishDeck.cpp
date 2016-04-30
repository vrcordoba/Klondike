
#include "SpanishDeck.hpp"

namespace Models
{

SpanishDeck::SpanishDeck()
{
   totalNumCardsM = NUM_CARDS_IN_SPANISH_DECK;
   numCardsPerSuitM = NUM_CARDS_PER_SUIT_IN_SPANISH_DECK;
}

SpanishDeck::~SpanishDeck()
{
}

Deck* SpanishDeck::clone()
{
   return new SpanishDeck();
}

void SpanishDeck::buildDeck()
{
   Deck::buildDeck(NUM_COLOURS_IN_SPANISH_DECK);
}

}
