#ifndef MODELS_PILE_HPP_
#define MODELS_PILE_HPP_

#include <deque>
#include "Card.hpp"
#include "MovementDestination.hpp"

namespace Models
{

class Pile : public MovementDestination
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

protected:
   Card getTopCard() const;

private:
   std::deque<Card> cardsM;
};

}

#endif
