
#include "StartController.hpp"

#include <cassert>
#include "State.hpp"
#include "DeckType.hpp"
#include "OperationControllerVisitor.hpp"
#include "ClosedInterval.hpp"

namespace Controllers
{

StartController::StartController(Models::Game& game) : Controller(game)
{
}

StartController::~StartController()
{
}

void StartController::start(std::uint8_t numPlayers,
   GameType gameType, Configuration::DeckType::Type typeDeck)
{
   assert(Utils::ClosedInterval(Controller::getNumPlayers()).includes(numPlayers));
   // gameControllerBuilder
   if (GameType::NEW == gameType)
   {
      Controller::initializeGame(typeDeck);
      Controller::setState(Models::State::GAME);
   }
   else
   {
      Controller::initializeGame(typeDeck, false);
      Controller::setState(Models::State::LOAD);
   }
}

void StartController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

}
