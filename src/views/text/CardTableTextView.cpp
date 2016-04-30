
#include "CardTableTextView.hpp"

#include <vector>
#include <string>
#include "CardTextViewPrototyper.hpp"
#include "CardTableController.hpp"
#include "CardView.hpp"
#include "IO.hpp"

namespace Views
{

CardTableTextView::CardTableTextView(Controllers::CardTableController* cardTableController)
   : CardTableView(cardTableController), ioM(Utils::IO::getInstance())
{
   buildCardView();
}

CardTableTextView::~CardTableTextView()
{
   delete cardViewM;
}

void CardTableTextView::buildCardView()
{
   cardViewM = CardTextViewPrototyper().getView();
}

void CardTableTextView::show()
{
   showDelimiter();
   showDeck();
   showWaste();
   showFoundations();
   showTableaus();
   showDelimiter();
   showScore();
   showDelimiter();
}

void CardTableTextView::showDelimiter() const
{
   ioM.writeString("==================================================");
}

void CardTableTextView::showDeck()
{
   ioM.writeStringNotEndingLine("Deck: ");
   showPile(cardTableControllerM->getDeck());
   ioM.writeString("");
}

void CardTableTextView::showWaste()
{
   ioM.writeStringNotEndingLine("Waste: ");
   showPile(cardTableControllerM->getWaste());
   ioM.writeString("");
}

void CardTableTextView::showFoundations()
{
   for (std::uint8_t i = 0; i < cardTableControllerM->getNumFoundations(); ++i)
   {
      ioM.writeStringNotEndingLine("Foundation " + std::to_string(i + 1) + ": ");
      showOnlyFirstCardInPile(cardTableControllerM->getFoundation(i));
      ioM.writeString("");
   }
}

void CardTableTextView::showTableaus()
{
   for (std::uint8_t i = 0; i < cardTableControllerM->getNumTableaus(); ++i)
   {
      ioM.writeStringNotEndingLine("Tableau " + std::to_string(i + 1) + ": ");
      showPile(cardTableControllerM->getTableau(i));
      ioM.writeString("");
   }
}

void CardTableTextView::showPile(const std::vector<Controllers::FacadeCard>& pile)
{
   for (auto card : pile)
      cardViewM->show(card);
}

void CardTableTextView::showOnlyFirstCardInPile(const std::vector<Controllers::FacadeCard>& pile)
{
   std::size_t pileSize = pile.size();
   if (pileSize > 0)
      cardViewM->show(pile[pileSize - 1]);
}

void CardTableTextView::showScore()
{
   std::string scoreString("Score: ");
   scoreString += std::to_string(cardTableControllerM->getScore());
   ioM.writeString(scoreString);
}

}
