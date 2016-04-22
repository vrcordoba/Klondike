
#include "Controller.hpp"

#include "Game.hpp"
#include "KlondikeConfiguration.hpp"

namespace Controllers
{

Controller::Controller(Models::Game& game) : gameM(game)
{
}

Controller::~Controller()
{
}

void Controller::initializeGame(std::uint8_t typeDeck)
{
   if (std::numeric_limits<std::uint8_t>::max() == typeDeck)
      typeDeck = Configuration::KlondikeConfiguration::getInstance().getDeckType();
   gameM.initializeGame(typeDeck);
}

void Controller::setState(Models::State newState)
{
   gameM.setState(newState);
}

std::uint8_t Controller::getNumPlayers() const
{
   return gameM.getNumPlayers();
}

std::uint8_t Controller::getNumTableaus() const
{
   return gameM.getNumTableaus();
}

std::uint8_t Controller::getNumFoundations() const
{
   return gameM.getNumFoundations();
}

std::uint8_t Controller::getNumCardsToDraw() const
{
   return gameM.getNumCardsToDraw();
}

Models::CardTable* Controller::getCardTable() const
{
   return gameM.getCardTable();
}

Models::Pile* Controller::getDeck() const
{
   return &(gameM.getDeck());
}

Models::Pile* Controller::getWaste() const
{
   return &(gameM.getWaste());
}

Models::Pile* Controller::getTableau(std::uint8_t tableauIndex) const
{
   return &(gameM.getTableau(tableauIndex));
}

Models::Pile* Controller::getFoundation(std::uint8_t foundationIndex) const
{
   return &(gameM.getFoundation(foundationIndex));
}

void Controller::transferCard(Models::Pile& originPile,
   Models::Pile& destinationPile)
{
   gameM.transferCard(originPile, destinationPile);
}

bool Controller::isGameWon() const
{
   return gameM.isGameWon();
}

}

