#ifndef MODELS_DECKMANAGER_HPP_
#define MODELS_DECKMANAGER_HPP_

#include <cstdint>

namespace Models
{

class Deck;

class DeckManager final
{
public:
   DeckManager();
   ~DeckManager();

   Deck* getDeck(std::uint8_t deckType);

private:
   Deck* deckM;
};

}

#endif
