#ifndef CONFIGURATION_KLONDIKECONFIGURATION_HPP_
#define CONFIGURATION_KLONDIKECONFIGURATION_HPP_

#include <list>
#include <string>
#include "DeckType.hpp"
#include "ViewType.hpp"
#include "SaveType.hpp"
#include "ControllerType.hpp"

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

   ViewType getViewType() const;
   SaveType getSaveType() const;
   ControllerType getControllerType() const;

private:
   KlondikeConfiguration();

   std::list<std::string> readConfiguration() const;
   void interpretReadConfiguration(const std::list<std::string>& configurations);

   void setControllerType(const std::string& configuration);
   void setViewType(const std::string& configuration);
   void setSaverType(const std::string& configuration);

   const std::string CONFIGURATION_FILE = "klondike.conf";
   DeckType deckTypeM;
   ViewType viewTypeM;
   SaveType saveTypeM;
   ControllerType controllerTypeM;
};

}

#endif
