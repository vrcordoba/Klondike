
#include "StartController.hpp"

#include "State.hpp"
#include "DeckType.hpp"
#include "OperationControllerVisitor.hpp"
#include "Logic.hpp"
#include "GameControllerPrototyper.hpp"

namespace Controllers
{

StartController::StartController(Models::Game& game, Logic* logic) : Controller(game),
   logicM(logic)
{
}

StartController::~StartController()
{
}

void StartController::start(std::uint8_t numPlayers,
   GameType gameType, Configuration::DeckType::Type typeDeck)
{
   logicM->setGameController(
      GameControllerPrototyper(Controller::getGame()).getGameController(numPlayers));
   if (GameType::NEW == gameType)
   {
      Controller::initializeGame(typeDeck);
      Controller::setState(Models::State::GAME);
   }
   else
   {
      Controller::setState(Models::State::LOAD);
   }
}

void StartController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

}
