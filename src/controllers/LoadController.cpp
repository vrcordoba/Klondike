
#include "LoadController.hpp"

#include "OperationControllerVisitor.hpp"
#include "State.hpp"
#include "KlondikeConfiguration.hpp"
#include "PermanentMedium.hpp"
#include "PermanentMediumPrototyper.hpp"
#include "PermanentMediumReader.hpp"
#include "Card.hpp"
#include "Pile.hpp"

namespace Controllers
{

LoadController::LoadController(Models::Game& game) : Controller(game)
{
}

LoadController::~LoadController()
{
}

void LoadController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

bool LoadController::fileAlreadyExists(const std::string& saveFileName)
{
   Utils::PermanentMediumReader* saveFile =
      Utils::PermanentMediumPrototyper().getReader(
         Configuration::KlondikeConfiguration::getInstance().getPermanentMediumType());
   bool alreadyExists = saveFile->alreadyExists(saveFileName);
   delete saveFile;
   return alreadyExists;
}

void LoadController::load(const std::string& saveFileName)
{
   Utils::PermanentMediumReader* saveFile =
      Utils::PermanentMediumPrototyper().getReader(
         Configuration::KlondikeConfiguration::getInstance().getPermanentMediumType());
   saveFile->open(saveFileName);
   Configuration::KlondikeConfiguration::getInstance().setDeckType(
      static_cast<Configuration::DeckType::Type>(saveFile->getNumericField()));
   Controller::setScore(saveFile->getNumericField());
   loadPile(saveFile, Controller::getDeck());
   loadPile(saveFile, Controller::getWaste());
   for (std::uint8_t i = 0; i < Controller::getNumFoundations(); ++i)
      loadPile(saveFile, Controller::getFoundation(i));
   for (std::uint8_t i = 0; i < Controller::getNumTableaus(); ++i)
      loadPile(saveFile, Controller::getTableau(i));
   delete saveFile;
   Controller::setState(Models::State::GAME);
}

void LoadController::loadPile(Utils::PermanentMediumReader* saveFile, Models::Pile* pile)
{
   std::list<std::string> composedField = saveFile->getComposedField();
   Models::Pile temporaryPile;
   for (auto field : composedField)
   {
      Models::Card card;
      card.fromString(field);
      temporaryPile.prependCard(card);
   }
   std::size_t numCardsInTemporaryPile = temporaryPile.getNumCards();
   for (std::size_t i = 0; i < numCardsInTemporaryPile; ++i)
      Controller::transferCard(temporaryPile, *pile);
}

}
