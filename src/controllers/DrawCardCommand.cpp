
#include "DrawCardCommand.hpp"

#include "CommandVisitor.hpp"
#include "Controller.hpp"
#include "Pile.hpp"

namespace Controllers
{

DrawCardCommand::DrawCardCommand() : CardCommand(), numMovedCardsM(0)
{
}

DrawCardCommand::~DrawCardCommand()
{
}

bool DrawCardCommand::accept(CommandVisitor* commandVisitor)
{
   return commandVisitor->visit(this);
}

void DrawCardCommand::setController(Controller* controller)
{
   CardCommand::setController(controller);
}

void DrawCardCommand::execute()
{
   Models::Pile* deck = CardCommand::getController()->getDeck();
   Models::Pile* waste = CardCommand::getController()->getWaste();
   if (0 == deck->getNumCards())
   {
      std::uint8_t numCardsInWaste = waste->getNumCards();
      moveCards(waste, deck, numCardsInWaste);
      deck->setUpturnCards(numCardsInWaste, false);
   }
   else
   {
      numMovedCardsM = deck->getNumCards() > CardCommand::getController()->getNumCardsToDraw() ?
         CardCommand::getController()->getNumCardsToDraw() : deck->getNumCards();
      moveCards(deck, waste, numMovedCardsM);
      waste->setUpturnCards(numMovedCardsM, true);
   }
}

void DrawCardCommand::undo()
{
   Models::Pile* deck = CardCommand::getController()->getDeck();
   Models::Pile* waste = CardCommand::getController()->getWaste();
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
