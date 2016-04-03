#ifndef MODELS_SPANISHDECK_HPP_
#define MODELS_SPANISHDECK_HPP_

#include "Deck.hpp"

namespace Models
{

class Card;

class SpanishDeck final : public Deck
{
public:
   SpanishDeck();
   ~SpanishDeck();

   SpanishDeck(const SpanishDeck&) = delete;
   SpanishDeck& operator=(const SpanishDeck&) = delete;

   void buildDeck();

private:
   static const std::uint8_t NUM_CARDS_IN_SPANISH_DECK = 40;
   static const std::uint8_t NUM_CARDS_PER_SUIT_IN_SPANISH_DECK = 10;
};

}

#endif
