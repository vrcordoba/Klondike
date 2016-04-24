#ifndef MODELS_DECK_HPP_
#define MODELS_DECK_HPP_

#include <cstdint>
#include "Pile.hpp"
#include "DeckType.hpp"

namespace Models
{

class Card;

class Deck : public Pile
{
private:

public:
   Deck(std::uint8_t numCards, std::uint8_t numCardsPerSuit);
   virtual ~Deck();

   explicit Deck(const Deck&);
   Deck& operator=(const Deck&);

   virtual Configuration::DeckType::Type type() = 0;
   virtual Deck* clone() = 0;

   void shuffle();
   virtual void buildDeck() = 0;

   bool isTheLowestCardInTheSuit(const Card& card) const;
   bool isTheHighestCardInTheSuit(const Card& card) const;

   std::uint8_t getTotalNumCards() const;
   std::uint8_t getNumCardsPerSuit() const;
   std::uint8_t getNumSuits() const;

private:
   std::uint8_t totalNumCardsM;
   std::uint8_t numCardsPerSuitM;
   static const std::uint8_t LOWEST_CARD_IN_THE_SUIT = 0;
};

}

#endif
