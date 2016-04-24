#ifndef MODELS_DECKPROTOTYPER_HPP_
#define MODELS_DECKPROTOTYPER_HPP_

#include <cstdint>
#include <map>
#include "Deck.hpp"
#include "DeckType.hpp"

namespace Models
{

class Deck;

class DeckPrototyper final
{
public:
   DeckPrototyper();
   ~DeckPrototyper();

   Deck* getDeck(Configuration::DeckType::Type deckType);

private:
   std::map<Configuration::DeckType::Type, Deck*> deckPrototypesM;
};

}

#endif
