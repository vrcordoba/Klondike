
#include "LocalStartController.hpp"

#include <cstdint>
#include <vector>
#include <string>
#include "OperationControllerVisitor.hpp"
#include "Game.hpp"
#include "DeckBuilder.hpp"

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
}

std::vector<std::string> LocalStartController::getDecks() const
{
   return deckBuilderM.getDecks();
}

void LocalStartController::accept(const OperationControllerVisitor&
   operationControllerVisitor)
{
   return;
}

}
