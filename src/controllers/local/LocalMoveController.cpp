
#include "LocalMoveController.hpp"

#include "OperationControllerVisitor.hpp"

namespace Controllers
{

LocalMoveController::LocalMoveController(Models::Game& game) : LocalController(game)
{
}

LocalMoveController::~LocalMoveController()
{
}

void LocalMoveController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

void LocalMoveController::move()
{
}

}
