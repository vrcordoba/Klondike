#ifndef MODELS_DECKBUILDER_HPP_
#define MODELS_DECKBUILDER_HPP_

#include <cstdint>
#include <vector>
#include <string>
#include "DeckType.hpp"

namespace Models
{

class Deck;

class DeckBuilder final
{
public:
   DeckBuilder();
   ~DeckBuilder();

   Deck* build(std::uint8_t deckType);

   std::vector<std::string> getDecks() const;
   DeckType::Name getDeckType() const;

private:
   Deck* deckM;
   DeckType deckTypeM;
};

}

#endif
