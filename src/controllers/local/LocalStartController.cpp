
#include "LocalStartController.hpp"

#include <cassert>
#include "Game.hpp"
#include "State.hpp"
#include "Deck.hpp"
#include "OperationControllerVisitor.hpp"
#include "ClosedInterval.hpp"
#include "CardTable.hpp"

namespace Controllers
{

LocalStartController::LocalStartController(Models::Game& game)
   : LocalController(game)
{
}

LocalStartController::~LocalStartController()
{
}

void LocalStartController::start(std::uint8_t numPlayers,
   std::uint8_t newOrSavedOption, std::uint8_t typeDeck)
{
   assert(Utils::ClosedInterval(LocalController::getNumPlayers()).includes(numPlayers));
   // gameControllerBuilder
   // newOrSave
   LocalController::initializeGame(typeDeck);
   LocalController::setState(Models::State::GAME);
   return;
}

void LocalStartController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

}
