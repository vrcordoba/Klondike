#ifndef VIEWS_TEXT_CARDTEXTVIEW_HPP_
#define VIEWS_TEXT_CARDTEXTVIEW_HPP_

#include <vector>
#include <string>
#include "CardView.hpp"

namespace Models
{
   class Card;
}

namespace Views
{

class CardTextView : public CardView
{
public:
   virtual ~CardTextView();
   virtual std::string show(const Models::Card& card) const;

protected:
   virtual void constructRepresentation() = 0;
   std::vector<std::string> numberRepresentationM;
   std::vector<std::string> suitRepresentationM;
};

}

#endif
