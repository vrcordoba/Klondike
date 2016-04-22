
#include "KlondikeConfiguration.hpp"

#include "FileReader.hpp"

namespace Configuration
{

KlondikeConfiguration::KlondikeConfiguration() : deckTypeM(), viewTypeM(ViewType::TEXT),
   saveTypeM(SaveType::PLAIN_TEXT)
{
   interpretReadConfiguration(readConfiguration());
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

ViewType KlondikeConfiguration::getViewType() const
{
   return viewTypeM;
}

SaveType KlondikeConfiguration::getSaveType() const
{
   return saveTypeM;
}

std::list<std::string> KlondikeConfiguration::readConfiguration() const
{
   Utils::FileReader fileReader(CONFIGURATION_FILE);
   std::list<std::string> configurations;
   if (fileReader.isOk())
   {
      bool continueReading;
      do
      {
         std::string configuration;
         continueReading = fileReader.getLine(configuration);
         if (not configuration.empty())
            configurations.push_back(configuration);
      } while (continueReading);
   }
   return configurations;
}

void KlondikeConfiguration::interpretReadConfiguration(
   const std::list<std::string>& configurations)
{
   for (std::string configuration : configurations)
   {
      if (configuration.find("views:") != std::string::npos)
         setViewType(configuration);
      else if (configuration.find("savers:") != std::string::npos)
         setSaverType(configuration);
   }
}

void KlondikeConfiguration::setViewType(const std::string& configuration)
{
   if (configuration.find("text") != std::string::npos)
      viewTypeM = ViewType::TEXT;
   else if (configuration.find("graphical") != std::string::npos)
      viewTypeM = ViewType::GRAPHICAL;
}

void KlondikeConfiguration::setSaverType(const std::string& configuration)
{
   if (configuration.find("plain_text") != std::string::npos)
      saveTypeM = SaveType::PLAIN_TEXT;
}

}
