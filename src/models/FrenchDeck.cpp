
#include "FrenchDeck.hpp"

namespace Models
{

FrenchDeck::FrenchDeck()
{
   totalNumCardsM = NUM_CARDS_IN_FRENCH_DECK;
   numCardsPerSuitM = NUM_CARDS_PER_SUIT_IN_FRENCH_DECK;
}

FrenchDeck::~FrenchDeck()
{
}

Deck* FrenchDeck::clone()
{
   return new FrenchDeck();
}

void FrenchDeck::buildDeck()
{
   Deck::buildDeck(NUM_COLOURS_IN_FRENCH_DECK);
}

}
