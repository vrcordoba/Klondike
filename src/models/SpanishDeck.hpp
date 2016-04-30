#ifndef MODELS_SPANISHDECK_HPP_
#define MODELS_SPANISHDECK_HPP_

#include <cstdint>
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

   Deck* clone();

   void buildDeck();

private:
   const std::uint8_t NUM_CARDS_IN_SPANISH_DECK = 40;
   const std::uint8_t NUM_CARDS_PER_SUIT_IN_SPANISH_DECK = 10;
   const std::uint8_t NUM_COLOURS_IN_SPANISH_DECK = 4;
};

}

#endif
