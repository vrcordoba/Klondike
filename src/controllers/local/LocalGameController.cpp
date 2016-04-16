
#include "LocalGameController.hpp"

#include "OperationControllerVisitor.hpp"
#include "CardTableController.hpp"
#include "Command.hpp"

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

bool LocalGameController::isValidCommand(const Command& command) const
{
   return true;
}

void LocalGameController::applyCommand(const Command& command) const
{
}

CardTableController* LocalGameController::getCardTableController()
{
   return &cardTableControllerM;
}

}
