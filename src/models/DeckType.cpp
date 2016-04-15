
#include "DeckType.hpp"

namespace Models
{

DeckType::DeckType() : deckTypesDescriptionM(),nameM(Name::SPANISH)
{
   deckTypesDescriptionM.push_back("Spanish");
   deckTypesDescriptionM.push_back("French");
}

DeckType::~DeckType()
{
}

std::vector<std::string> DeckType::getDeckDescriptions() const
{
   return deckTypesDescriptionM;
}

void DeckType::setDeckType(Name name)
{
   nameM = name;
}

DeckType::Name DeckType::getDeckType() const
{
   return nameM;
}

}
