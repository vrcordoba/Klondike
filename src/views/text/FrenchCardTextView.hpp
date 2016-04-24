#ifndef VIEWS_TEXT_FRENCHCARDTEXTVIEW_HPP_
#define VIEWS_TEXT_FRENCHCARDTEXTVIEW_HPP_

#include "CardTextView.hpp"
#include "DeckType.hpp"

namespace Views
{

class FrenchCardTextView: public CardTextView
{
public:
   FrenchCardTextView();
   ~FrenchCardTextView();

   FrenchCardTextView(const FrenchCardTextView&) = delete;
   FrenchCardTextView& operator=(const FrenchCardTextView&) = delete;

   Configuration::DeckType::Type type();
   CardView* clone();

   void constructRepresentation();

private:
   const char* SPADE = "\u2660";
   const char* DIAMOND = "\u2666";
   const char* CLUB = "\u2663";
   const char* HEART = "\u2665";
};

}

#endif
