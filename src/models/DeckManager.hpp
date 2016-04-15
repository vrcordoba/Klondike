#ifndef MODELS_DECKMANAGER_HPP_
#define MODELS_DECKMANAGER_HPP_

#include <cstdint>
#include <list>
#include <string>
#include "DeckType.hpp"

namespace Models
{

class Deck;

class DeckManager final
{
public:
   DeckManager();
   ~DeckManager();

   Deck* getDeck(std::uint8_t deckType);

   std::list<std::string> getDeckDescriptions() const;
   DeckType::Name getDeckType() const;

private:
   Deck* deckM;
   DeckType deckTypeM;
};

}

#endif
