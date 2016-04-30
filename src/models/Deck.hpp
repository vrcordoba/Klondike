#ifndef MODELS_DECK_HPP_
#define MODELS_DECK_HPP_

#include <cstdint>
#include "Pile.hpp"

namespace Models
{

class Card;

class Deck : public Pile
{
private:

public:
   Deck();
   virtual ~Deck();

   explicit Deck(const Deck&);
   Deck& operator=(const Deck&);

   virtual Deck* clone() = 0;

   void shuffle();
   virtual void buildDeck() = 0;
   void buildDeck(std::uint8_t numColours);

   bool isTheLowestCardInTheSuit(const Card& card) const;
   bool isTheHighestCardInTheSuit(const Card& card) const;

   std::uint8_t getTotalNumCards() const;
   std::uint8_t getNumCardsPerSuit() const;
   std::uint8_t getNumSuits() const;

protected:
   std::uint8_t totalNumCardsM;
   std::uint8_t numCardsPerSuitM;

private:
   const std::uint8_t LOWEST_CARD_IN_THE_SUIT = 0;
};

}

#endif
