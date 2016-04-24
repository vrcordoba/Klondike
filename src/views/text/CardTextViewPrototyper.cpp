
#include "CardTextViewPrototyper.hpp"

#include <cassert>
#include "KlondikeConfiguration.hpp"
#include "DeckType.hpp"
#include "FrenchCardTextView.hpp"
#include "SpanishCardTextView.hpp"

namespace Views
{

CardTextViewPrototyper::CardTextViewPrototyper()
{
   cardViewPrototypesM[Configuration::DeckType::Type::SPANISH] = new SpanishCardTextView();
   cardViewPrototypesM[Configuration::DeckType::Type::FRENCH] = new FrenchCardTextView();
}

CardTextViewPrototyper::~CardTextViewPrototyper()
{
}

CardView* CardTextViewPrototyper::getView() const
{
   std::map<Configuration::DeckType::Type, CardView*>::const_iterator viewIt =
      cardViewPrototypesM.find(Configuration::KlondikeConfiguration::getInstance().getDeckType());
   assert(viewIt != cardViewPrototypesM.end());
   CardView* cardView = viewIt->second->clone();
   cardView->constructRepresentation();
   return cardView;
}

}
