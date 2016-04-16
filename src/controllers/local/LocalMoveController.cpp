
#include "LocalMoveController.hpp"

#include "MovementOriginDestinationType.hpp"
#include "Pile.hpp"
#include "Command.hpp"

namespace Controllers
{

LocalMoveController::LocalMoveController(Models::Game& game)
   : LocalController(game), movementHistoryM()
{
}

LocalMoveController::~LocalMoveController()
{
}

bool LocalMoveController::isValidMovement(const Command& command) const
{
   std::vector<std::uint8_t> additionalArguments = command.getAdditionalArguments();
   if (not isValidOrigin(additionalArguments))
      return false;
   if (not isValidDestination(additionalArguments))
      return false;
   return true;
}

bool LocalMoveController::isValidOrigin(
   const std::vector<std::uint8_t>& additionalArguments) const
{
   if (not isIndexValid(additionalArguments[0], additionalArguments[1]))
      return false;
   if (not pileCompatibleWithNumberOfCards(additionalArguments[0], additionalArguments[4]))
      return false;
   if (not areEnoughCardsInPile(additionalArguments[0], additionalArguments[1],
         additionalArguments[4]))
      return false;
   return true;
}

bool LocalMoveController::isIndexValid(std::uint8_t pile, std::uint8_t index) const
{
   bool isIndexValid = true;
   if (MovementOriginDestinationType::TABLEAU == pile)
   {
      isIndexValid = (LocalController::getNumTableaus() >= index and 0 < index);
   }
   else if (MovementOriginDestinationType::FOUNDATION == pile)
   {
      isIndexValid = (LocalController::getNumFoundations() >= index and 0 < index);
   }
   return isIndexValid;
}

bool LocalMoveController::pileCompatibleWithNumberOfCards(
   std::uint8_t pile, std::uint8_t numCards) const
{
   if (numCards > 1 and MovementOriginDestinationType::TABLEAU != pile)
      return false;
   return true;
}

bool LocalMoveController::areEnoughCardsInPile(
   std::uint8_t pileId, std::uint8_t index, std::uint8_t numCards) const
{
   Models::Pile* pile = getPile(pileId, index);
   return (pile->getNumCards() >= numCards);
}

bool LocalMoveController::isValidDestination(
   const std::vector<std::uint8_t>& additionalArguments) const
{
   if (not isIndexValid(additionalArguments[2], additionalArguments[3]))
      return false;
   if (not pileCompatibleWithNumberOfCards(additionalArguments[2], additionalArguments[4]))
      return false;
   if (not isCardStackableInDestination(additionalArguments))
      return false;
   return true;
}

bool LocalMoveController::isCardStackableInDestination(
   const std::vector<std::uint8_t>& additionalArguments) const
{
   Models::Card cardToMove = getCardToMove(additionalArguments);
   Models::Pile* destinationPile = getPile(additionalArguments[2],
      additionalArguments[3]);
   return destinationPile->isValidDestination(cardToMove);
}

Models::Card LocalMoveController::getCardToMove(
   const std::vector<std::uint8_t>& additionalArguments) const
{
   Models::Pile* originPile = getPile(additionalArguments[0],
      additionalArguments[1]);
   return originPile->getCardAt(
      originPile->getNumCards() - additionalArguments[4]);
}

Models::Pile* LocalMoveController::getPile(std::uint8_t pileId,
   std::uint8_t pileIndex) const
{
   Models::Pile* pile;
   if (MovementOriginDestinationType::WASTE == pileId)
   {
      pile = LocalController::getWaste();
   }
   else if (MovementOriginDestinationType::FOUNDATION == pileId)
   {
      pile = LocalController::getFoundation(pileIndex - 1);
   }
   else
   {
      pile = LocalController::getTableau(pileIndex - 1);
   }
   return pile;
}

void LocalMoveController::applyMovement(const Command& command)
{
   std::vector<std::uint8_t> additionalArguments = command.getAdditionalArguments();
   Models::Pile* originPile = getPile(additionalArguments[0],
      additionalArguments[1]);
   Models::Pile* destinationPile = getPile(additionalArguments[2],
      additionalArguments[3]);
   moveCards(originPile, destinationPile, additionalArguments[4]);
   if (originPile->getNumCards() > 0)
      originPile->upturnTopCard();
   movementHistoryM.store(command);
}

void LocalMoveController::moveCards(Models::Pile* originPile,
   Models::Pile* destinationPile, std::uint8_t numCards)
{
   Models::Pile cardsToMove;
   for (std::uint8_t i = 0; i < numCards; ++i)
   {
      cardsToMove.addCard(originPile->takeCard());
   }
   for (std::uint8_t i = 0; i < numCards; ++i)
   {
      LocalController::transferCard(cardsToMove, *destinationPile);
   }
}

}
