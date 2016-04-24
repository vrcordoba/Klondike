
#include "SaveController.hpp"

#include "OperationControllerVisitor.hpp"

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
   /*Utils::PermanentMediumReader* saveFile =
      Utils::PermanentMediumPrototyper::getReader();*/
   return true;

}

void SaveController::saveGame(const std::string& saveFileName)
{
}

}
