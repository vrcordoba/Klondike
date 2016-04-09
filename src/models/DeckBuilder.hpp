#ifndef MODELS_DECKBUILDER_HPP_
#define MODELS_DECKBUILDER_HPP_

#include <cstdint>
#include <vector>
#include <string>

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

private:

   enum
   {
      SPANISH,
      FRENCH
   };

   std::vector<std::string> deckTypesDescriptionM;
};

}

#endif
