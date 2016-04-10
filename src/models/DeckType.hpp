#ifndef MODELS_DECKTYPE_HPP_
#define MODELS_DECKTYPE_HPP_

#include <cstdint>
#include <vector>
#include <string>

namespace Models
{

class DeckType final
{
public:
   DeckType();
   ~DeckType();

   DeckType(const DeckType&) = delete;
   DeckType& operator=(const DeckType&) = delete;

   enum Name
   {
      SPANISH = 1,
      FRENCH
   };

   std::vector<std::string> getDecks() const;
   DeckType::Name getDeckType() const;
   void setDeckType(Name name);

private:
   std::vector<std::string> deckTypesDescriptionM;
   Name nameM;
};

}

#endif
