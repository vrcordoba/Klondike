
#include "CardTextViewBuilder.hpp"

#include <cassert>
#include "CardTableController.hpp"
#include "FrenchCardTextView.hpp"
#include "SpanishCardTextView.hpp"
#include "DeckType.hpp"

namespace Views
{

CardTextViewBuilder::CardTextViewBuilder(
   const Controllers::CardTableController* cardTableController) :
   cardTableControllerM(cardTableController)
{
}

CardTextViewBuilder::~CardTextViewBuilder()
{
}

CardView* CardTextViewBuilder::build() const
{
   CardView* cardView;
   if (Models::DeckType::SPANISH == cardTableControllerM->getDeckType())
   {
      cardView = new SpanishCardTextView();
   }
   else if (Models::DeckType::FRENCH == cardTableControllerM->getDeckType())
   {
      cardView = new FrenchCardTextView();
   }
   else
   {
      assert(false);
   }
   return cardView;
}

}
