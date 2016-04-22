
#include "MoveController.hpp"

#include "PileType.hpp"
#include "Card.hpp"
#include "Pile.hpp"
#include "MoveCommand.hpp"
#include "DrawCardCommand.hpp"

namespace Controllers
{

MoveController::MoveController(Models::Game& game)
   : Controller(game), movementHistoryM()
{
}

MoveController::~MoveController()
{
}

bool MoveController::isValidMovement(const MoveCommand* command) const
{
   return isValidOrigin(command) and isValidDestination(command);
}

bool MoveController::isValidOrigin(const MoveCommand* command) const
{
   return isIndexValid(command->getOriginPileType(), command->getOriginPileNumber()) and
      pileCompatibleWithNumberOfCards(command->getOriginPileType(), command->getNumCards()) and
      areEnoughCardsInPile(command->getOriginPileType(), command->getOriginPileNumber(),
         command->getNumCards());
}

bool MoveController::isIndexValid(std::uint8_t pile, std::uint8_t index) const
{
   bool isIndexValid = true;
   if (Models::PileType::TABLEAU == pile)
      isIndexValid = (Controller::getNumTableaus() >= index and 0 < index);
   else if (Models::PileType::FOUNDATION == pile)
      isIndexValid = (Controller::getNumFoundations() >= index and 0 < index);
   return isIndexValid;
}

bool MoveController::pileCompatibleWithNumberOfCards(
   std::uint8_t pile, std::uint8_t numCards) const
{
   return (numCards <= 1) or (Models::PileType::TABLEAU == pile);
}

bool MoveController::areEnoughCardsInPile(
   std::uint8_t pileId, std::uint8_t index, std::uint8_t numCards) const
{
   Models::Pile* pile = getPile(pileId, index);
   return (pile->getNumCards() >= numCards);
}

bool MoveController::isValidDestination(
   const MoveCommand* command) const
{
   return isIndexValid(command->getDestinationPileType(), command->getDestinationPileNumber()) and
      pileCompatibleWithNumberOfCards(command->getDestinationPileType(), command->getNumCards()) and
      isCardStackableInDestination(command);
}

bool MoveController::isCardStackableInDestination(
   const MoveCommand* command) const
{
   Models::Card cardToMove = getCardToMove(command);
   Models::Pile* destinationPile = getPile(command->getDestinationPileType(),
      command->getDestinationPileNumber());
   return destinationPile->isValidDestination(cardToMove);
}

Models::Card MoveController::getCardToMove(
   const MoveCommand* command) const
{
   Models::Pile* originPile = getPile(command->getOriginPileType(),
      command->getOriginPileNumber());
   return originPile->getCardAt(
      originPile->getNumCards() - command->getNumCards());
}

Models::Pile* MoveController::getPile(std::uint8_t pileId,
   std::uint8_t pileIndex) const
{
   Models::Pile* pile;
   if (Models::PileType::WASTE == pileId)
      pile = Controller::getWaste();
   else if (Models::PileType::FOUNDATION == pileId)
      pile = Controller::getFoundation(pileIndex - 1);
   else
      pile = Controller::getTableau(pileIndex - 1);
   return pile;
}

void MoveController::applyMovement(MoveCommand* command)
{
   Models::Pile* originPile = getPile(command->getOriginPileType(),
      command->getOriginPileNumber());
   Models::Pile* destinationPile = getPile(command->getDestinationPileType(),
      command->getDestinationPileNumber());
   moveCards(originPile, destinationPile, command->getNumCards());
   if (originPile->getNumCards() > 0)
      originPile->setUpturnCards(1, true);
   movementHistoryM.store(command);
}

void MoveController::moveCards(Models::Pile* originPile,
   Models::Pile* destinationPile, std::uint8_t numCards)
{
   Models::Pile cardsToMove;
   for (std::uint8_t i = 0; i < numCards; ++i)
      cardsToMove.addCard(originPile->takeCard());
   for (std::uint8_t i = 0; i < numCards; ++i)
      Controller::transferCard(cardsToMove, *destinationPile);
}

void MoveController::applyDrawCard(DrawCardCommand* command)
{
   Models::Pile* deck = Controller::getDeck();
   Models::Pile* waste = Controller::getWaste();
   if (0 == deck->getNumCards())
   {
      std::uint8_t numCardsInWaste = waste->getNumCards();
      moveCards(waste, deck, numCardsInWaste);
      deck->setUpturnCards(numCardsInWaste, false);
   }
   else
   {
      std::uint8_t numCardsToMoveToWaste = deck->getNumCards() > Controller::getNumCardsToDraw() ?
         Controller::getNumCardsToDraw() : deck->getNumCards();
      moveCards(deck, waste, numCardsToMoveToWaste);
      waste->setUpturnCards(numCardsToMoveToWaste, true);
   }
   movementHistoryM.store(command);
}

}
