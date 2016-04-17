#ifndef MODELS_TABLEAU_HPP_
#define MODELS_TABLEAU_HPP_

#include "Pile.hpp"

namespace Models
{

class Deck;
class Card;

class Tableau final: public Pile
{
public:
   explicit Tableau(Deck& deck);
   ~Tableau();

   Tableau(const Tableau& otherTableau);
   Tableau& operator=(const Tableau& otherTableau);

   bool isValidDestination(const Card& card) const;

private:
   Deck& deckM;
};

}

#endif
