
#include "LocalMoveController.hpp"

#include "OperationControllerVisitor.hpp"
#include "CardTableController.hpp"

namespace Controllers
{

LocalMoveController::LocalMoveController(Models::Game& game) : LocalController(game),
   cardTableControllerM(game)
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

CardTableController* LocalMoveController::getCardTableController()
{
   return &cardTableControllerM;
}

}
