#ifndef MODELS_DECK_HPP_
#define MODELS_DECK_HPP_

#include "Pile.hpp"

namespace Models
{

class Deck : public Pile
{
private:

public:
   Deck();
   ~Deck();

   Deck(const Deck&) = delete;
   Deck& operator=(const Deck&) = delete;

   void shuffle();

};

}

#endif
