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
   explicit Foundation(const Deck& deck);
   ~Foundation();

   Foundation(const Foundation&) = delete;
   Foundation& operator=(const Foundation&) = delete;

   bool validTarget(const Card& card) const;
   bool isFoundationComplete() const;

private:
   const Deck& deckM;
};

}

#endif
