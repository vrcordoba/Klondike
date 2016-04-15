#ifndef MODELS_DECKTYPE_HPP_
#define MODELS_DECKTYPE_HPP_

#include <cstdint>
#include <list>
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

   std::list<std::string> getDeckDescriptions() const;
   DeckType::Name getDeckType() const;
   void setDeckType(Name name);

private:
   std::list<std::string> deckTypesDescriptionM;
   Name nameM;
};

}

#endif
