
#include "MoveCommand.hpp"

#include <cassert>
#include "CardCommandVisitor.hpp"
#include "GameController.hpp"
#include "Card.hpp"
#include "Pile.hpp"
#include "PileType.hpp"
#include "Score.hpp"

namespace Controllers
{

MoveCommand::MoveCommand() : originPileTypeM(), originPileNumberM(), destinationPileTypeM(),
   destinationPileNumberM(), numCardsM(), previousCardInPileNotUpturnedM(false)
{
}

MoveCommand::~MoveCommand()
{
}

MoveCommand::MoveCommand(const MoveCommand& otherMoveCommand) :
   originPileTypeM(otherMoveCommand.originPileTypeM),
   originPileNumberM(otherMoveCommand.originPileNumberM),
   destinationPileTypeM(otherMoveCommand.destinationPileTypeM),
   destinationPileNumberM(otherMoveCommand.destinationPileNumberM),
   numCardsM(otherMoveCommand.numCardsM),
   previousCardInPileNotUpturnedM(otherMoveCommand.previousCardInPileNotUpturnedM)
{
   gameControllerM = otherMoveCommand.gameControllerM;
}

void MoveCommand::accept(CardCommandVisitor* cardCommandVisitor)
{
   cardCommandVisitor->visit(this);
}

Command* MoveCommand::clone()
{
   return new MoveCommand();
}

void MoveCommand::setAdditionalArguments(const std::vector<std::uint8_t>& additionalArguments)
{
   assert(5 == additionalArguments.size());
   originPileTypeM = additionalArguments[0];
   originPileNumberM = additionalArguments[1];
   destinationPileTypeM = additionalArguments[2];
   destinationPileNumberM = additionalArguments[3];
   numCardsM = additionalArguments[4];
}

bool MoveCommand::isValid()
{
   return (isValidOrigin() and isValidDestination());
}

bool MoveCommand::isValidOrigin() const
{
   return isIndexValid(originPileTypeM, originPileNumberM) and
      pileCompatibleWithNumberOfCards(originPileTypeM) and
      areEnoughCardsInOriginPile();
}

bool MoveCommand::isValidDestination() const
{
   return isIndexValid(destinationPileTypeM, destinationPileNumberM) and
      pileCompatibleWithNumberOfCards(destinationPileTypeM) and
      isCardStackableInDestination();
}

bool MoveCommand::isIndexValid(std::uint8_t pile, std::uint8_t index) const
{
   bool isIndexValid = true;
   if (Models::PileType::TABLEAU == pile)
      isIndexValid = (getController()->getNumTableaus() >= index and 0 < index);
   else if (Models::PileType::FOUNDATION == pile)
      isIndexValid = (getController()->getNumFoundations() >= index and 0 < index);
   return isIndexValid;
}

bool MoveCommand::pileCompatibleWithNumberOfCards(
   std::uint8_t pile) const
{
   return (numCardsM <= 1) or (Models::PileType::TABLEAU == pile);
}

bool MoveCommand::areEnoughCardsInOriginPile() const
{
   Models::Pile* pile = getPile(originPileTypeM, originPileNumberM);
   return (pile->getNumCards() >= numCardsM);
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
   return originPile->getCardAt(originPile->getNumCards() - numCardsM);
}

void MoveCommand::execute()
{
   Models::Pile* originPile = getPile(originPileTypeM, originPileNumberM);
   Models::Pile* destinationPile = getPile(destinationPileTypeM, destinationPileNumberM);
   moveCards(originPile, destinationPile, numCardsM);
   if (originPile->getNumCards() > 0 and not originPile->isTopCardUnturned())
   {
      previousCardInPileNotUpturnedM = true;
      originPile->setUpturnCards(1, true);
      updateScore(true);
   }
   else
   {
      previousCardInPileNotUpturnedM = false;
      updateScore(false);
   }
}

void MoveCommand::undo()
{
   Models::Pile* originPile = getPile(originPileTypeM, originPileNumberM);
   Models::Pile* destinationPile = getPile(destinationPileTypeM, destinationPileNumberM);
   if (previousCardInPileNotUpturnedM)
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
      pile = getController()->getWaste();
   else if (Models::PileType::FOUNDATION == pileId)
      pile = getController()->getFoundation(pileIndex - 1);
   else
      pile = getController()->getTableau(pileIndex - 1);
   return pile;
}

void MoveCommand::updateScore(bool upturnScore, bool negativeScore)
{
   Models::Score& score = getController()->getScore();
   if (upturnScore)
      score.turnOverTableauCardScore(negativeScore);
   score.movementScore(originPileTypeM, destinationPileTypeM, numCardsM,
      negativeScore);
}

}
