
#include "GameController.hpp"

#include "OperationControllerVisitor.hpp"

namespace Controllers
{

GameController::GameController(Models::Game& game) : Controller(game),
   cardTableControllerM(game), movementHistoryM()
{
}

GameController::~GameController()
{
}

void GameController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

CardTableController* GameController::getCardTableController()
{
   return &cardTableControllerM;
}

bool GameController::isGameWon() const
{
   return Controller::isGameWon();
}

MovementHistory* GameController::getMovementHistory()
{
   return &movementHistoryM;
}

void GameController::emptyMovementHistory()
{
   movementHistoryM.emptyHistory();
}

}
