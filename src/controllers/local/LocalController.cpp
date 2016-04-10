
#include "LocalController.hpp"

#include "Game.hpp"

namespace Controllers
{

LocalController::LocalController(Models::Game& game) : gameM(game)
{
}

LocalController::~LocalController()
{
}

void LocalController::setState(Models::State newState)
{
   gameM.setState(newState);
}

std::uint8_t LocalController::getNumPlayers() const
{
   return gameM.getNumPlayers();
}

std::uint8_t LocalController::getNumTableaus() const
{
   return gameM.getNumTableaus();
}

Models::CardTable* LocalController::getCardTable() const
{
   return gameM.getCardTable();
}

void LocalController::setCardTable(Models::CardTable* cardTable)
{
   gameM.setCardTable(cardTable);
}

Models::DeckType::Name LocalController::getDeckType() const
{
   return gameM.getDeckType();
}

void LocalController::setDeckType(Models::DeckType::Name name)
{
   gameM.setDeckType(name);
}

}
