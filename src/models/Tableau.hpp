#ifndef MODELS_TABLEAU_HPP_
#define MODELS_TABLEAU_HPP_

#include "Pile.hpp"
#include "MovementDestination.hpp"

namespace Models
{

class Deck;
class Card;

class Tableau final: public Pile, MovementDestination
{
public:
   explicit Tableau(const Deck& deck);
   ~Tableau();

   Tableau(const Tableau&);
   Tableau& operator=(const Tableau&) = delete;

   bool validDestination(const Card& card) const;

private:
   const Deck& deckM;
};

}

#endif
