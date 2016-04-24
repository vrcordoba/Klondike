#ifndef CONFIGURATION_DECKTYPE_HPP_
#define CONFIGURATION_DECKTYPE_HPP_

#include <cstdint>
#include <list>
#include <string>

namespace Configuration
{

class DeckType final
{
public:
   DeckType();
   ~DeckType();

   DeckType(const DeckType&) = delete;
   DeckType& operator=(const DeckType&) = delete;

   enum class Type : std::uint8_t
   {
      SPANISH = 1,
      FRENCH,
      UNKNOWN
   };

   std::list<std::string> getDeckDescriptions() const;
   Type getDeckType() const;
   void setDeckType(Type name);

private:
   std::list<std::string> deckTypesDescriptionM;
   Type typeM;
};

}

#endif
