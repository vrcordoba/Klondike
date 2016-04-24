#ifndef VIEWS_TEXT_SPANISHCARDTEXTVIEW_HPP_
#define VIEWS_TEXT_SPANISHCARDTEXTVIEW_HPP_

#include "CardTextView.hpp"
#include "DeckType.hpp"

namespace Views
{

class SpanishCardTextView: public CardTextView
{
public:
   SpanishCardTextView();
   ~SpanishCardTextView();

   SpanishCardTextView(const SpanishCardTextView&) = delete;
   SpanishCardTextView& operator=(const SpanishCardTextView&) = delete;

   Configuration::DeckType::Type type();
   CardView* clone();

   void constructRepresentation();
};

}

#endif
