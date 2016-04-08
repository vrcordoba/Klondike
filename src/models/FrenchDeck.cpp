
#include "FrenchDeck.hpp"

#include <cstdint>
#include "Deck.hpp"
#include "Card.hpp"
#include "Suit.hpp"

namespace Models
{

FrenchDeck::FrenchDeck()
   : Deck(NUM_CARDS_IN_FRENCH_DECK, NUM_CARDS_PER_SUIT_IN_FRENCH_DECK)
{
}

FrenchDeck::~FrenchDeck()
{
}

void FrenchDeck::buildDeck()
{
   const std::uint8_t numCards = getTotalNumCards();
   const std::uint8_t numCardsPerSuit = getNumCardsPerSuit();
   for (std::uint8_t i = 0; i < numCards; ++i)
   {
      addCard(Card(i % numCardsPerSuit,
         Suit(i / numCardsPerSuit,
            (i / numCardsPerSuit) % 2)));
   }
}

}
