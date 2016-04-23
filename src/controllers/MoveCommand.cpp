
#include "MoveCommand.hpp"

#include "CommandVisitor.hpp"
#include "Controller.hpp"
#include "Card.hpp"
#include "Pile.hpp"
#include "PileType.hpp"
#include "Score.hpp"

namespace Controllers
{

MoveCommand::MoveCommand(const std::vector<std::uint8_t>& additionalArguments) :
   CardCommand(), originPileTypeM(additionalArguments[0]),
   originPileNumberM(additionalArguments[1]), destinationPileTypeM(additionalArguments[2]),
   destinationPileNumberM(additionalArguments[3]), numCardsM(additionalArguments[4])
{
}

MoveCommand::~MoveCommand()
{
}

bool MoveCommand::accept(CommandVisitor* commandVisitor)
{
   return commandVisitor->visit(this);
}

std::uint8_t MoveCommand::getOriginPileType() const
{
   return originPileTypeM;
}

std::uint8_t MoveCommand::getOriginPileNumber() const
{
   return originPileNumberM;
}

std::uint8_t MoveCommand::getDestinationPileType() const
{
   return destinationPileTypeM;
}

std::uint8_t MoveCommand::getNumCards() const
{
   return numCardsM;
}

bool MoveCommand::isValidOrigin() const
{
   return isIndexValid(originPileTypeM, originPileNumberM) and
      pileCompatibleWithNumberOfCards(originPileTypeM) and
      areEnoughCardsInPile(originPileTypeM, originPileNumberM);
}

bool MoveCommand::isIndexValid(std::uint8_t pile, std::uint8_t index) const
{
   bool isIndexValid = true;
   if (Models::PileType::TABLEAU == pile)
      isIndexValid = (CardCommand::getController()->getNumTableaus() >= index and 0 < index);
   else if (Models::PileType::FOUNDATION == pile)
      isIndexValid = (CardCommand::getController()->getNumFoundations() >= index and 0 < index);
   return isIndexValid;
}

bool MoveCommand::pileCompatibleWithNumberOfCards(
   std::uint8_t pile) const
{
   return (numCardsM <= 1) or (Models::PileType::TABLEAU == pile);
}

bool MoveCommand::areEnoughCardsInPile(
   std::uint8_t pileId, std::uint8_t index) const
{
   Models::Pile* pile = getPile(pileId, index);
   return (pile->getNumCards() >= numCardsM);
}

bool MoveCommand::isValidDestination() const
{
   return isIndexValid(destinationPileTypeM, destinationPileNumberM) and
      pileCompatibleWithNumberOfCards(destinationPileTypeM) and
      isCardStackableInDestination();
}

bool MoveCommand::isCardStackableInDestination() const
{
   Models::Card cardToMove = getCardToMove();
   Models::Pile* destinationPile = getPile(destinationPileTypeM, destinationPileNumberM);
   return destinationPile->isValidDestination(cardToMove);
}

Models::Card MoveCommand::getCardToMove() const
{
   Models::Pile* originPile = getPile(originPileTypeM, originPileNumberM);
   return originPile->getCardAt(
      originPile->getNumCards() - numCardsM);
}

void MoveCommand::setController(Controller* controller)
{
   CardCommand::setController(controller);
}

void MoveCommand::execute()
{
   Models::Pile* originPile = getPile(originPileTypeM, originPileNumberM);
   Models::Pile* destinationPile = getPile(destinationPileTypeM, destinationPileNumberM);
   moveCards(originPile, destinationPile, numCardsM);
   if (originPile->getNumCards() > 0 and not originPile->isTopCardUnturned())
   {
      originPile->setUpturnCards(1, true);
      updateScore(true);
   }
   else
      updateScore(false);
}

void MoveCommand::undo()
{
   Models::Pile* originPile = getPile(originPileTypeM, originPileNumberM);
   Models::Pile* destinationPile = getPile(destinationPileTypeM, destinationPileNumberM);
   if (originPile->getNumCards() > 0 and originPile->isTopCardUnturned()
      and Models::PileType::WASTE != originPileTypeM)
   {
      originPile->setUpturnCards(1, false);
      updateScore(true, true);
   }
   else
      updateScore(false, true);
   moveCards(destinationPile, originPile, numCardsM);
}

Models::Pile* MoveCommand::getPile(std::uint8_t pileId,
   std::uint8_t pileIndex) const
{
   Models::Pile* pile;
   if (Models::PileType::WASTE == pileId)
      pile = CardCommand::getController()->getWaste();
   else if (Models::PileType::FOUNDATION == pileId)
      pile = CardCommand::getController()->getFoundation(pileIndex - 1);
   else
      pile = CardCommand::getController()->getTableau(pileIndex - 1);
   return pile;
}

void MoveCommand::updateScore(bool upturnScore, bool negativeScore)
{
   Models::Score& score = CardCommand::getController()->getScore();
   if (upturnScore)
      score.turnOverTableauCardScore(negativeScore);
   score.movementScore(originPileTypeM, destinationPileTypeM, numCardsM,
      negativeScore);
}

}
