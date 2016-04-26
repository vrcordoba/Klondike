
#include "SaveController.hpp"

#include "OperationControllerVisitor.hpp"
#include "PermanentMediumReader.hpp"
#include "PermanentMediumPrototyper.hpp"
#include "KlondikeConfiguration.hpp"

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
   return saveFile->alreadyExists(saveFileName);
}

void SaveController::saveGame(const std::string& saveFileName)
{
   Controller::setState(Models::State::GAME);
}

}
