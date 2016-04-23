
#include "DrawCardCommand.hpp"

#include "CommandVisitor.hpp"
#include "Controller.hpp"
#include "Pile.hpp"

namespace Controllers
{

DrawCardCommand::DrawCardCommand() : CardCommand()
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
      std::uint8_t numCardsToMoveToWaste =
         deck->getNumCards() > CardCommand::getController()->getNumCardsToDraw() ?
         CardCommand::getController()->getNumCardsToDraw() : deck->getNumCards();
      moveCards(deck, waste, numCardsToMoveToWaste);
      waste->setUpturnCards(numCardsToMoveToWaste, true);
   }
}

void DrawCardCommand::undo()
{
}

}
