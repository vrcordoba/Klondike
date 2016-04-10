
#include "LocalController.hpp"

#include "Game.hpp"
#include "State.hpp"

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

void LocalController::setCardTable(Models::CardTable* cardTable)
{
   gameM.setCardTable(cardTable);
}

}
