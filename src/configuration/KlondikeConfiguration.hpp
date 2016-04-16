#ifndef CONFIGURATION_KLONDIKECONFIGURATION_HPP_
#define CONFIGURATION_KLONDIKECONFIGURATION_HPP_

#include "FileReader.hpp"

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

private:
   KlondikeConfiguration();

   void readConfiguration();

   Utils::FileReader fileReaderM;
};

}

#endif
