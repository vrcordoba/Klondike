
#include "LocalGameController.hpp"

#include "OperationControllerVisitor.hpp"
#include "CardTableController.hpp"

namespace Controllers
{

LocalGameController::LocalGameController(Models::Game& game) : LocalController(game),
   cardTableControllerM(game)
{
}

LocalGameController::~LocalGameController()
{
}

void LocalGameController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

void LocalGameController::isValidMove() const
{
}

void LocalGameController::move() const
{
}

CardTableController* LocalGameController::getCardTableController()
{
   return &cardTableControllerM;
}

}
