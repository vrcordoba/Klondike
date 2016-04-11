#ifndef MODELS_TABLEAU_HPP_
#define MODELS_TABLEAU_HPP_

#include "Pile.hpp"
#include "MovementDestination.hpp"

namespace Models
{

class Deck;
class Card;

class Tableau final: public Pile, public MovementDestination
{
public:
   explicit Tableau(Deck& deck);
   ~Tableau();

   Tableau(const Tableau& otherTableau);
   Tableau& operator=(const Tableau& otherTableau);

   bool validDestination(const Card& card) const;

private:
   Deck& deckM;
};

}

#endif
