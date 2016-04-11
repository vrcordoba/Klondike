#ifndef MODELS_FOUNDATION_HPP_
#define MODELS_FOUNDATION_HPP_

#include "Pile.hpp"
#include "MovementDestination.hpp"

namespace Models
{

class Deck;
class Card;

class Foundation final : public Pile, MovementDestination
{
public:
   explicit Foundation(Deck& deck);
   ~Foundation();

   Foundation(const Foundation& otherFoundation);
   Foundation& operator=(const Foundation& otherFoundation);

   bool validDestination(const Card& card) const;
   bool isFoundationComplete() const;

private:
   Deck& deckM;
};

}

#endif
