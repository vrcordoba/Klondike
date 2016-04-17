
#include "KlondikeConfiguration.hpp"

namespace Configuration
{

KlondikeConfiguration::KlondikeConfiguration() : fileReaderM("Klondike.conf"), deckTypeM()
{
}

KlondikeConfiguration::~KlondikeConfiguration()
{
}

DeckType::Type KlondikeConfiguration::getDeckType() const
{
   return deckTypeM.getDeckType();
}

void KlondikeConfiguration::setDeckType(DeckType::Type type)
{
   deckTypeM.setDeckType(type);
}

std::list<std::string> KlondikeConfiguration::getDeckDescriptions() const
{
   return deckTypeM.getDeckDescriptions();
}

void KlondikeConfiguration::readConfiguration()
{
}

}
