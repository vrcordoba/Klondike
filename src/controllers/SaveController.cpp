
#include "SaveController.hpp"

#include "OperationControllerVisitor.hpp"
#include "PermanentMediumReader.hpp"
#include "PermanentMediumWriter.hpp"
#include "PermanentMediumPrototyper.hpp"
#include "KlondikeConfiguration.hpp"
#include "Pile.hpp"
#include "Card.hpp"
#include "Score.hpp"

namespace Controllers
{

SaveController::SaveController(Models::Game& game) : Controller(game)
{

}

SaveController::~SaveController()
{
}

void SaveController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

bool SaveController::fileAlreadyExists(const std::string& saveFileName)
{
   Utils::PermanentMediumReader* saveFile =
      Utils::PermanentMediumPrototyper().getReader(
         Configuration::KlondikeConfiguration::getInstance().getPermanentMediumType());
   bool alreadyExists = saveFile->alreadyExists(saveFileName);
   delete saveFile;
   return alreadyExists;
}

void SaveController::saveGame(const std::string& saveFileName)
{
   Utils::PermanentMediumWriter* saveFile =
      Utils::PermanentMediumPrototyper().getWriter(
         Configuration::KlondikeConfiguration::getInstance().getPermanentMediumType());
   saveFile->open(saveFileName);
   saveCardTable(saveFile);
   delete saveFile;
   Controller::setState(Models::State::GAME);
}

void SaveController::saveCardTable(Utils::PermanentMediumWriter* saveFile)
{
   saveFile->writeNumericField(Configuration::KlondikeConfiguration::getInstance().getDeckType());
   saveFile->writeNumericField(Controller::getScore().getScore());
   savePile(saveFile, Controller::getDeck());
   savePile(saveFile, Controller::getWaste());
   for (std::uint8_t i = 0; i < Controller::getNumFoundations(); ++i)
      savePile(saveFile, Controller::getFoundation(i));
   for (std::uint8_t i = 0; i < Controller::getNumTableaus(); ++i)
      savePile(saveFile, Controller::getTableau(i));
}

void SaveController::savePile(Utils::PermanentMediumWriter* saveFile, Models::Pile* pile)
{
   std::list<std::string> pileField;
   for (auto card : pile->getCards())
      pileField.push_back(card.toString());
   saveFile->writeComposedField(pileField);
}

}
