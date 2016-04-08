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

   void addCard(const Card& card);
   Card takeCard();
   std::size_t getNumCards() const;

protected:
   std::deque<Card> getCards() const;
   Card getTopCard() const;

private:
   std::deque<Card> cardsM;
};

}

#endif
