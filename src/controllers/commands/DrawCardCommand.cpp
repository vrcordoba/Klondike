
#include "DrawCardCommand.hpp"

#include "CardCommandVisitor.hpp"
#include "GameController.hpp"
#include "Pile.hpp"

namespace Controllers
{

DrawCardCommand::DrawCardCommand() : numMovedCardsM(0)
{
}

DrawCardCommand::~DrawCardCommand()
{
}

DrawCardCommand::DrawCardCommand(const DrawCardCommand& otherDrawCardCommand) :
   numMovedCardsM(otherDrawCardCommand.numMovedCardsM)
{
   gameControllerM = otherDrawCardCommand.gameControllerM;
}

void DrawCardCommand::accept(CardCommandVisitor* cardCommandVisitor)
{
   cardCommandVisitor->visit(this);
}

Command* DrawCardCommand::clone()
{
   return new DrawCardCommand();
}

void DrawCardCommand::execute()
{
   Models::Pile* deck = getController()->getDeck();
   Models::Pile* waste = getController()->getWaste();
   if (0 == deck->getNumCards())
   {
      std::uint8_t numCardsInWaste = waste->getNumCards();
      moveCards(waste, deck, numCardsInWaste);
      deck->setUpturnCards(numCardsInWaste, false);
   }
   else
   {
      numMovedCardsM = deck->getNumCards() > getController()->getNumCardsToDraw() ?
         getController()->getNumCardsToDraw() : deck->getNumCards();
      moveCards(deck, waste, numMovedCardsM);
      waste->setUpturnCards(numMovedCardsM, true);
   }
}

void DrawCardCommand::undo()
{
   Models::Pile* deck = getController()->getDeck();
   Models::Pile* waste = getController()->getWaste();
   if (0 == waste->getNumCards())
   {
      std::uint8_t numCardsInDeck = deck->getNumCards();
      moveCards(deck, waste, numCardsInDeck);
      waste->setUpturnCards(numCardsInDeck, true);
   }
   else
   {
      moveCards(waste, deck, numMovedCardsM);
      deck->setUpturnCards(numMovedCardsM, false);
   }
}

}
