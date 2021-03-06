#ifndef MODELS_FRENCHDECK_HPP_
#define MODELS_FRENCHDECK_HPP_

#include <cstdint>
#include "Deck.hpp"

namespace Models
{

class Card;

class FrenchDeck final : public Deck
{
public:
   FrenchDeck();
   ~FrenchDeck();

   FrenchDeck(const FrenchDeck&) = delete;
   FrenchDeck& operator=(const FrenchDeck&) = delete;

   Deck* clone();

   void buildDeck();

private:
   const std::uint8_t NUM_CARDS_IN_FRENCH_DECK = 52;
   const std::uint8_t NUM_CARDS_PER_SUIT_IN_FRENCH_DECK = 13;
   const std::uint8_t NUM_COLOURS_IN_FRENCH_DECK = 2;
};

}

#endif
