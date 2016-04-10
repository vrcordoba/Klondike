
#include "LocalContinueController.hpp"

#include "OperationControllerVisitor.hpp"
#include "Game.hpp"

namespace Controllers
{

LocalContinueController::LocalContinueController(Models::Game& game)
   : LocalController(game)
{
}

LocalContinueController::~LocalContinueController()
{
}

void LocalContinueController::accept(OperationControllerVisitor* operationControllerVisitor)
{

}

void LocalContinueController::resume(bool otherGame)
{

}

}

