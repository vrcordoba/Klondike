
#include "CardTextViewManager.hpp"

#include <cassert>
#include "KlondikeConfiguration.hpp"
#include "DeckType.hpp"
#include "FrenchCardTextView.hpp"
#include "SpanishCardTextView.hpp"

namespace Views
{

CardTextViewManager::CardTextViewManager()
{
}

CardTextViewManager::~CardTextViewManager()
{
}

CardView* CardTextViewManager::getView() const
{
   CardView* cardView;
   if (Configuration::DeckType::SPANISH ==
      Configuration::KlondikeConfiguration::getInstance().getDeckType())
   {
      cardView = new SpanishCardTextView();
   }
   else if (Configuration::DeckType::FRENCH ==
      Configuration::KlondikeConfiguration::getInstance().getDeckType())
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
