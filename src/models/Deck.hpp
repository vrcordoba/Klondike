#ifndef MODELS_DECK_HPP_
#define MODELS_DECK_HPP_

#include <cstdint>
#include <vector>

#include "Card.hpp"

namespace Models
{

class Deck
{
private:

public:
   Deck();
   ~Deck();

   Deck(const Deck&) = delete;
   Deck& operator=(const Deck&) = delete;

   void shuffle();
   void addCard(const Card* card);
   const Card* takeCard();
   std::size_t getNumCards() const;

private:
   std::vector<const Card*> cardsM;
};

}

#endif
