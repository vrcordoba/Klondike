
#include "KlondikeConfiguration.hpp"

#include "PermanentMediumReaderPrototyper.hpp"
#include "PermanentMediumReader.hpp"

namespace Configuration
{

KlondikeConfiguration::KlondikeConfiguration() : deckTypeM(), viewTypeM(ViewType::TEXT)
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

std::list<std::string> KlondikeConfiguration::readConfiguration() const
{
   Utils::PermanentMediumReader* configurationReader =
      Utils::PermanentMediumReaderPrototyper::makePrototype(
         Utils::PermanentMediumReaderPrototyper::PLAIN_TEXT);
   configurationReader->open(CONFIGURATION_FILE);
   std::list<std::string> configurations;
   if (configurationReader->isOk())
   {
      bool continueReading;
      do
      {
         std::string configuration;
         continueReading = configurationReader->getLine(configuration);
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
   }
}

void KlondikeConfiguration::setViewType(const std::string& configuration)
{
   if (configuration.find("text") != std::string::npos)
      viewTypeM = ViewType::TEXT;
   else if (configuration.find("graphical") != std::string::npos)
      viewTypeM = ViewType::GRAPHICAL;
}

}
