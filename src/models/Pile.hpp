#ifndef MODELS_PILE_HPP_
#define MODELS_PILE_HPP_

#include <deque>
#include "Card.hpp"

namespace Models
{

class Pile
{
public:
   Pile();
   virtual ~Pile();

   Pile(const Pile& otherPile);
   Pile& operator=(const Pile& otherPile);

   void addCard(const Card& card);
   Card takeCard();
   std::size_t getNumCards() const;

   std::deque<Card> getCards() const;

protected:
   Card getTopCard() const;

private:
   std::deque<Card> cardsM;
};

}

#endif
