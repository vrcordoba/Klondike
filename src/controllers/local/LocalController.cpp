
#include "LocalController.hpp"

#include "Game.hpp"
#include "KlondikeConfiguration.hpp"

namespace Controllers
{

LocalController::LocalController(Models::Game& game) : gameM(game)
{
}

LocalController::~LocalController()
{
}

void LocalController::initializeGame(std::uint8_t typeDeck)
{
   if (std::numeric_limits<std::uint8_t>::max() == typeDeck)
      typeDeck = Configuration::KlondikeConfiguration::getInstance().getDeckType();
   gameM.initializeGame(typeDeck);
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

std::uint8_t LocalController::getNumFoundations() const
{
   return gameM.getNumFoundations();
}

std::uint8_t LocalController::getNumCardsToDraw() const
{
   return gameM.getNumCardsToDraw();
}

Models::CardTable* LocalController::getCardTable() const
{
   return gameM.getCardTable();
}

Models::Pile* LocalController::getDeck() const
{
   return &(gameM.getDeck());
}

Models::Pile* LocalController::getWaste() const
{
   return &(gameM.getWaste());
}

Models::Pile* LocalController::getTableau(std::uint8_t tableauIndex) const
{
   return &(gameM.getTableau(tableauIndex));
}

Models::Pile* LocalController::getFoundation(std::uint8_t foundationIndex) const
{
   return &(gameM.getFoundation(foundationIndex));
}

void LocalController::transferCard(Models::Pile& originPile,
   Models::Pile& destinationPile)
{
   gameM.transferCard(originPile, destinationPile);
}

bool LocalController::isGameWon() const
{
   return gameM.isGameWon();
}

}

