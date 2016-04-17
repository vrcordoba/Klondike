#ifndef CONFIGURATION_KLONDIKECONFIGURATION_HPP_
#define CONFIGURATION_KLONDIKECONFIGURATION_HPP_

#include <list>
#include <string>
#include "FileReader.hpp"
#include "DeckType.hpp"

namespace Configuration
{

class KlondikeConfiguration final
{
public:
   ~KlondikeConfiguration();

   static KlondikeConfiguration& getInstance()
   {
      static KlondikeConfiguration instance;
      return instance;
   }

   KlondikeConfiguration(const KlondikeConfiguration&) = delete;
   KlondikeConfiguration& operator=(const KlondikeConfiguration&) = delete;

   DeckType::Type getDeckType() const;
   void setDeckType(DeckType::Type type);
   std::list<std::string> getDeckDescriptions() const;

private:
   KlondikeConfiguration();

   void readConfiguration();

   Utils::FileReader fileReaderM;
   DeckType deckTypeM;
};

}

#endif
