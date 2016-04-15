
#include "CardTextViewManager.hpp"

#include <cassert>
#include "CardTableController.hpp"
#include "FrenchCardTextView.hpp"
#include "SpanishCardTextView.hpp"
#include "DeckType.hpp"

namespace Views
{

CardTextViewManager::CardTextViewManager(
   const Controllers::CardTableController* cardTableController) :
   cardTableControllerM(cardTableController)
{
}

CardTextViewManager::~CardTextViewManager()
{
}

CardView* CardTextViewManager::getView() const
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
   cardView->constructRepresentation();
   return cardView;
}

}
