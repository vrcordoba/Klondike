#ifndef MODELS_FOUNDATION_HPP_
#define MODELS_FOUNDATION_HPP_

#include "Pile.hpp"

namespace Models
{

class Deck;
class Card;

class Foundation final : public Pile
{
public:
   explicit Foundation(Deck& deck);
   ~Foundation();

   Foundation(const Foundation& otherFoundation);
   Foundation& operator=(const Foundation& otherFoundation);

   bool isValidDestination(const Card& card) const;
   bool isFoundationComplete() const;

private:
   Deck& deckM;
};

}

#endif
