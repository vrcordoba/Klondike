
#include "Game.hpp"

namespace Models
{

class Deck;
class Pile;
class Tableau;
class Foundation;

Game::Game() : stateM(State::INITIAL), cardTableM(nullptr), historyM(), deckTypeNameM(DeckType::SPANISH)
{
}

Game::~Game()
{
}

std::uint8_t Game::getNumTableaus() const
{
   return NUM_TABLEAUS;
}

std::uint8_t Game::getNumFoundations() const
{
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
   return cardTableM;
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

Deck& Game::getDeck() const
{
   return cardTableM->getDeck();
}

Pile& Game::getWaste() const
{
   return cardTableM->getWaste();
}

Tableau& Game::getTableau(std::uint8_t tableauIndex) const
{
   return cardTableM->getTableau(tableauIndex);
}

Foundation& Game::getFoundation(std::uint8_t foundationIndex) const
{
   return cardTableM->getFoundation(foundationIndex);
}

std::uint8_t Game::getNumPlayers() const
{
   return NUM_PLAYERS;
}

void Game::execute(const Movement& movement)
{
   historyM.storeAndExecute(movement);
}

DeckType::Name Game::getDeckType() const
{
   return deckTypeNameM;
}

void Game::setDeckType(DeckType::Name name)
{
   deckTypeNameM = name;
}

}
