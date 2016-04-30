
#include "CardCommand.hpp"

#include <cassert>
#include "Controller.hpp"
#include "Pile.hpp"

namespace Controllers
{

CardCommand::CardCommand() : controllerM(nullptr)
{
}

CardCommand::~CardCommand()
{
}

void CardCommand::setController(Controller* controller)
{
   controllerM = controller;
}

Controller* CardCommand::getController() const
{
   assert(nullptr != controllerM);
   return controllerM;
}

void CardCommand::moveCards(Models::Pile* originPile,
   Models::Pile* destinationPile, std::uint8_t numCards)
{
   assert(nullptr != controllerM);
   Models::Pile cardsToMove;
   for (std::uint8_t i = 0; i < numCards; ++i)
      cardsToMove.appendCard(originPile->takeCard());
   for (std::uint8_t i = 0; i < numCards; ++i)
      controllerM->transferCard(cardsToMove, *destinationPile);
}

}
