
#include "DeckType.hpp"

namespace Configuration
{

DeckType::DeckType() : deckTypesDescriptionM(), typeM(Type::SPANISH)
{
   deckTypesDescriptionM.push_back("Spanish");
   deckTypesDescriptionM.push_back("French");
}

DeckType::~DeckType()
{
}

std::list<std::string> DeckType::getDeckDescriptions() const
{
   return deckTypesDescriptionM;
}

void DeckType::setDeckType(Type type)
{
   typeM = type;
}

DeckType::Type DeckType::getDeckType() const
{
   return typeM;
}

}
