
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

void LocalMoveController::isValidMove() const
{
}

void LocalMoveController::move() const
{
}

CardTableController* LocalMoveController::getCardTableController()
{
   return &cardTableControllerM;
}

}
