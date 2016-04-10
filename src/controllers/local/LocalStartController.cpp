
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
   : LocalController(game), cardTableM(nullptr)
{
}

LocalStartController::~LocalStartController()
{
   delete cardTableM;
}

void LocalStartController::start(std::uint8_t numPlayers,
   std::uint8_t newOrSavedOption, std::uint8_t typeDeck)
{
   assert(Utils::ClosedInterval(LocalController::getNumPlayers()).includes(numPlayers));
   // moveControllerBuilder
   // newOrSave
   buildCardTable(typeDeck);
   LocalController::setState(Models::State::MOVE);
   return;
}

std::vector<std::string> LocalStartController::getDecks() const
{
   return deckBuilderM.getDecks();
}

void LocalStartController::accept(OperationControllerVisitor* operationControllerVisitor)
{
   operationControllerVisitor->visit(this);
}

void LocalStartController::buildCardTable(std::uint8_t typeDeck)
{
   Models::Deck* deck = deckBuilderM.build(typeDeck);
   deck->buildDeck();
   cardTableM = new Models::CardTable(*deck, LocalController::getNumTableaus());
   LocalController::setCardTable(cardTableM);
}

}
