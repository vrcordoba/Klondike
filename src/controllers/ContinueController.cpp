
#include "ContinueController.hpp"

#include "PermanentMediumReaderPrototyper.hpp"
#include "OperationControllerVisitor.hpp"
#include "Score.hpp"
#include "Ranking.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

ContinueController::ContinueController(Models::Game& game)
   : Controller(game)
{
}

ContinueController::~ContinueController()
{
}

void ContinueController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

void ContinueController::ranking()
{
   Models::Score& score = Controller::getScore();
   Models::Ranking ranking(RANKING_FILE);
}

void ContinueController::resume(bool otherGame)
{
   if (otherGame)
   {
      Controller::initializeGame();
      Controller::setState(Models::State::GAME);
   }
   else
      Controller::setState(Models::State::END);
}

}

