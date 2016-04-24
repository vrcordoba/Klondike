
#include "SpanishDeck.hpp"

#include "Card.hpp"
#include "Suit.hpp"
#include "DeckPrototyper.hpp"

namespace Models
{

SpanishDeck::SpanishDeck()
   : Deck(NUM_CARDS_IN_SPANISH_DECK, NUM_CARDS_PER_SUIT_IN_SPANISH_DECK)
{
}

SpanishDeck::~SpanishDeck()
{
}

Configuration::DeckType::Type SpanishDeck::type()
{
   return Configuration::DeckType::Type::SPANISH;
}

Deck* SpanishDeck::clone()
{
   return new SpanishDeck();
}

void SpanishDeck::buildDeck()
{
   const std::uint8_t numCards = getTotalNumCards();
   const std::uint8_t numCardsPerSuit = getNumCardsPerSuit();
   for (std::uint8_t i = 0; i < numCards; ++i)
   {
      addCard(Card(i % numCardsPerSuit,
         Suit(i / numCardsPerSuit,
            i / numCardsPerSuit)));
   }
}

}
