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

   Card getCardAt(std::uint8_t index) const;

   virtual bool isValidDestination(const Card& card) const;

   void setUpturnCards(std::uint8_t numCards, bool upturn);

protected:
   void setCards(std::deque<Card>& cards);
   Card getTopCard() const;

private:
   std::deque<Card> cardsM;
};

}

#endif
