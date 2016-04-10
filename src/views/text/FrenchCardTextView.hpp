#ifndef VIEWS_TEXT_FRENCHCARDTEXTVIEW_HPP_
#define VIEWS_TEXT_FRENCHCARDTEXTVIEW_HPP_

#include "CardTextView.hpp"

namespace Views
{

class FrenchCardTextView: public CardTextView
{
public:
   FrenchCardTextView();
   ~FrenchCardTextView();

   FrenchCardTextView(const FrenchCardTextView&) = delete;
   FrenchCardTextView& operator=(const FrenchCardTextView&) = delete;

   void constructRepresentation();
};

}

#endif
