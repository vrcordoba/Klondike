
#include "CardTableTextView.hpp"

#include <vector>
#include <string>
#include "CardTextViewManager.hpp"
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
   cardViewM = CardTextViewManager(cardTableControllerM).getView();
}

void CardTableTextView::show()
{
   showDelimiter();
   showDeck();
   showWaste();
   showFoundations();
   showTableaus();
   showDelimiter();
}

void CardTableTextView::showDelimiter()
{
   ioM.writeString("==================================================");
}

void CardTableTextView::showDeck()
{
   ioM.writeString("Deck: " + showPile(cardTableControllerM->getDeck()));
}

void CardTableTextView::showWaste()
{
   ioM.writeString("Waste: " + showOnlyFirstCardInPile(cardTableControllerM->getWaste()));
}

void CardTableTextView::showFoundations()
{
   for (std::uint8_t i = 0; i < cardTableControllerM->getNumFoundations(); ++i)
   {
      ioM.writeString("Foundation " + std::to_string(i + 1) + ": "
         + showOnlyFirstCardInPile(cardTableControllerM->getFoundation(i)));
   }
}

void CardTableTextView::showTableaus()
{
   for (std::uint8_t i = 0; i < cardTableControllerM->getNumTableaus(); ++i)
   {
      ioM.writeString("Tableau " + std::to_string(i + 1) + ": "
         + showPile(cardTableControllerM->getTableau(i)));
   }
}

std::string CardTableTextView::showPile(const std::vector<Controllers::FacadeCard>& pile)
{
   std::string pileString;
   for (Controllers::FacadeCard card : pile)
   {
      pileString += cardViewM->show(card);
   }
   return pileString;
}

std::string CardTableTextView::showOnlyFirstCardInPile(const std::vector<Controllers::FacadeCard>& pile)
{
   std::string pileString;
   std::size_t pileSize = pile.size();
   if (pileSize > 0)
      pileString += cardViewM->show(pile[pileSize - 1]);
   return pileString;
}
}
