
#include "Game.hpp"

#include <cassert>
#include "CardTable.hpp"

namespace Models
{

class Pile;

Game::Game() : stateM(State::INITIAL), deckManagerM(), cardTableM(nullptr)
{
}

Game::~Game()
{
}

void Game::initializeGame(std::uint8_t typeDeck)
{
   Models::Deck* deck = deckManagerM.getDeck(typeDeck);
   if (nullptr != cardTableM)
      delete cardTableM;
   cardTableM = new Models::CardTable(*deck, getNumTableaus());
}

std::uint8_t Game::getNumTableaus() const
{
   return NUM_TABLEAUS;
}

std::uint8_t Game::getNumFoundations() const
{
   assert(nullptr != cardTableM);
   return cardTableM->getNumSuits();
}

State Game::getState() const
{
   return stateM;
}

void Game::setState(State newState)
{
   stateM = newState;
}

CardTable* Game::getCardTable() const
{
   assert(nullptr != cardTableM);
   return cardTableM;
}

void Game::setCardTable(CardTable* cardTable)
{
   cardTableM = cardTable;
}

void Game::transferCard(Pile& originPile, Pile& destinationPile)
{
   assert(nullptr != cardTableM);
   cardTableM->transferCard(originPile, destinationPile);
}

bool Game::isGameWon() const
{
   assert(nullptr != cardTableM);
   return cardTableM->isGameWon();
}

Pile& Game::getDeck() const
{
   assert(nullptr != cardTableM);
   return cardTableM->getDeck();
}

Pile& Game::getWaste() const
{
   assert(nullptr != cardTableM);
   return cardTableM->getWaste();
}

Pile& Game::getTableau(std::uint8_t tableauIndex) const
{
   assert(nullptr != cardTableM);
   return cardTableM->getTableau(tableauIndex);
}

Pile& Game::getFoundation(std::uint8_t foundationIndex) const
{
   assert(nullptr != cardTableM);
   return cardTableM->getFoundation(foundationIndex);
}

std::uint8_t Game::getNumPlayers() const
{
   return NUM_PLAYERS;
}

std::uint8_t Game::getNumCardsToDraw() const
{
   return NUM_CARDS_TO_DRAW;
}

}
