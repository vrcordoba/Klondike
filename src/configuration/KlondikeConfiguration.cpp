
#include "KlondikeConfiguration.hpp"

#include "PermanentMediumPrototyper.hpp"
#include "PermanentMediumReader.hpp"

namespace Configuration
{

KlondikeConfiguration::KlondikeConfiguration() : deckTypeM(), viewTypeM(ViewType::TEXT),
   permanentMediumTypeM(Utils::PermanentMedium::Type::PLAIN_TEXT)
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

Utils::PermanentMedium::Type KlondikeConfiguration::getPermanentMediumType() const
{
   return permanentMediumTypeM;
}

std::list<std::string> KlondikeConfiguration::readConfiguration() const
{
   Utils::PermanentMediumReader* configurationReader =
      Utils::PermanentMediumPrototyper().getReader(
         Utils::PermanentMedium::Type::PLAIN_TEXT);
   configurationReader->open(CONFIGURATION_FILE);
   std::list<std::string> configurations;
   if (configurationReader->isOk())
   {
      bool continueReading;
      do
      {
         std::string configuration;
         continueReading = configurationReader->getField(configuration);
         if (not configuration.empty())
            configurations.push_back(configuration);
      } while (continueReading);
   }
   delete configurationReader;
   return configurations;
}

void KlondikeConfiguration::interpretReadConfiguration(
   const std::list<std::string>& configurations)
{
   for (auto configuration : configurations)
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
