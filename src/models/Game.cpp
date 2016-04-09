
#include "Game.hpp"

#include "State.hpp"
#include "CardTable.hpp"

namespace Models
{

class Deck;
class Pile;
class Tableau;
class Foundation;

Game::Game() : stateM(State::INITIAL), cardTableM(nullptr)
{
}

Game::~Game()
{
}

std::uint8_t Game::getNumTableaus() const
{
   return NUM_TABLEAUS;
}

State Game::getState() const
{
   return stateM;
}

void Game::setState(State newState)
{
   stateM = newState;
}

void Game::setCardTable(CardTable* cardTable)
{
   cardTableM = cardTable;
}

void Game::transferCard(Pile& originPile, Pile& destinationPile)
{
   cardTableM->transferCard(originPile, destinationPile);
}

bool Game::isGameWon() const
{
   return cardTableM->isGameWon();
}

Deck& Game::getDeck()
{
   return cardTableM->getDeck();
}

Pile& Game::getWaste()
{
   return cardTableM->getWaste();
}

Tableau& Game::getTableau(std::uint8_t tableauIndex)
{
   return cardTableM->getTableau(tableauIndex);
}

Foundation& Game::getFoundation(std::uint8_t foundationIndex)
{
   return cardTableM->getFoundation(foundationIndex);
}

}
