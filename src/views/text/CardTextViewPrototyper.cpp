
#include "CardTextViewPrototyper.hpp"

#include <cassert>
#include <algorithm>
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
   std::for_each(std::begin(cardViewPrototypesM), std::end(cardViewPrototypesM),
      [] (std::pair<const Configuration::DeckType::Type, CardView*>& pair)
      {
         delete pair.second;
      });
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
