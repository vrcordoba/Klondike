
#include "Game.hpp"

#include "State.hpp"
#include "CardTable.hpp"

namespace Models
{

class Deck;
class Pile;
class Tableau;
class Foundation;

Game::Game(Deck& deck) : stateM(State::INITIAL), cardTableM(deck, NUM_TABLEAUS)
{
}

Game::~Game()
{
}

State Game::getState() const
{
   return stateM;
}

void Game::setState(State newState)
{
   stateM = newState;
}

void Game::transferCard(Pile& originPile, Pile& destinationPile)
{
   cardTableM.transferCard(originPile, destinationPile);
}

bool Game::isGameWon() const
{
   return cardTableM.isGameWon();
}

Deck& Game::getDeck()
{
   return cardTableM.getDeck();
}

Pile& Game::getWaste()
{
   return cardTableM.getWaste();
}

Tableau& Game::getTableau(std::uint8_t tableauIndex)
{
   return cardTableM.getTableau(tableauIndex);
}

Foundation& Game::getFoundation(std::uint8_t foundationIndex)
{
   return cardTableM.getFoundation(foundationIndex);
}

}
