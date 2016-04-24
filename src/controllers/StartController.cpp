
#include "StartController.hpp"

#include <cassert>
#include "Game.hpp"
#include "State.hpp"
#include "Deck.hpp"
#include "OperationControllerVisitor.hpp"
#include "ClosedInterval.hpp"
#include "CardTable.hpp"

namespace Controllers
{

StartController::StartController(Models::Game& game)
   : Controller(game)
{
}

StartController::~StartController()
{
}

void StartController::start(std::uint8_t numPlayers,
   std::uint8_t newOrSavedOption, std::uint8_t typeDeck)
{
   assert(Utils::ClosedInterval(Controller::getNumPlayers()).includes(numPlayers));
   // gameControllerBuilder
   // newOrSave
   Controller::initializeGame(static_cast<Configuration::DeckType::Type>(typeDeck));
   Controller::setState(Models::State::GAME);
   return;
}

void StartController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

}
