
#include "CardCommand.hpp"

#include "GameController.hpp"
#include "Pile.hpp"

namespace Controllers
{

CardCommand::CardCommand()
{
}

CardCommand::~CardCommand()
{
}

bool CardCommand::isUndoable()
{
   return true;
}

void CardCommand::moveCards(Models::Pile* originPile,
   Models::Pile* destinationPile, std::uint8_t numCards)
{
   Models::Pile cardsToMove;
   for (std::uint8_t i = 0; i < numCards; ++i)
      cardsToMove.appendCard(originPile->takeCard());
   for (std::uint8_t i = 0; i < numCards; ++i)
      getController()->transferCard(cardsToMove, *destinationPile);
}

}
