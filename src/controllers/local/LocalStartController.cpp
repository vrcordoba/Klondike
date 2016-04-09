
#include "LocalStartController.hpp"

#include "Game.hpp"
#include "State.hpp"
#include "DeckBuilder.hpp"
#include "Deck.hpp"
#include "OperationControllerVisitor.hpp"

namespace Controllers
{

LocalStartController::LocalStartController(Models::Game& game,
   Models::DeckBuilder& deckBuilder) : gameM(game),
   deckBuilderM(deckBuilder)
{
}

LocalStartController::~LocalStartController()
{
}

void LocalStartController::start(std::uint8_t numPlayers,
   std::uint8_t newOrSavedOption, std::uint8_t typeDeck) const
{
   // moveControllerBuilder
   // newOrSave
   //Models::Deck* deck = deckBuilderM.build(typeDeck);
   //gameM.setCardTable();
   gameM.setState(Models::State::MOVE);
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

}
