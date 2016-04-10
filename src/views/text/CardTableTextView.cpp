
#include "CardTableTextView.hpp"

#include <vector>
#include <string>
#include "CardTableController.hpp"
#include "CardTextViewBuilder.hpp"
#include "CardView.hpp"
#include "IO.hpp"
#include "Deck.hpp"
#include "Card.hpp"
#include "Pile.hpp"

namespace Views
{

CardTableTextView::CardTableTextView(Controllers::CardTableController* cardTableController)
   : ioM(), cardTableControllerM(cardTableController)
{
   buildCardView();
}

CardTableTextView::~CardTableTextView()
{
   delete cardViewM;
}

void CardTableTextView::buildCardView()
{
   cardViewM = CardTextViewBuilder(cardTableControllerM).build();
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
   Models::Deck& deck = cardTableControllerM->getDeck();
   ioM.writeString("Deck: " + showPile(deck));
}

void CardTableTextView::showWaste()
{
   Models::Pile& waste = cardTableControllerM->getWaste();
   ioM.writeString("Waste: " + showPile(waste));
}

void CardTableTextView::showFoundations()
{
   std::vector<Models::Pile> foundations = cardTableControllerM->getFoundations();
   std::uint8_t i = 1;
   for (Models::Pile pile : foundations)
   {
      ioM.writeString("Foundation " + std::to_string(i++) + ": " + showPile(pile));
   }
}

void CardTableTextView::showTableaus()
{
   std::vector<Models::Pile> tableaus = cardTableControllerM->getTableaus();
   std::uint8_t i = 1;
   for (Models::Pile pile : tableaus)
   {
      ioM.writeString("Tableau " + std::to_string(i++) + ": " + showPile(pile));
   }
}

std::string CardTableTextView::showPile(const Models::Pile& pile)
{
   std::deque<Models::Card> cards = pile.getCards();
   std::string pileString;
   for (Models::Card card : cards)
   {
      pileString += cardViewM->show(card);
   }
   return pileString;
}

}
