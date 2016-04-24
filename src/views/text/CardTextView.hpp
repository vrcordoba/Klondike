#ifndef VIEWS_TEXT_CARDTEXTVIEW_HPP_
#define VIEWS_TEXT_CARDTEXTVIEW_HPP_

#include <vector>
#include <string>
#include "CardView.hpp"
#include "DeckType.hpp"

namespace Controllers
{
class FacadeCard;
}

namespace Views
{

class CardTextView : public CardView
{
public:
   virtual ~CardTextView();

   virtual Configuration::DeckType::Type type() = 0;
   virtual CardView* clone() = 0;

   virtual std::string show(const Controllers::FacadeCard& card) const;
   virtual void constructRepresentation() = 0;

protected:
   std::vector<std::string> numberRepresentationM;
   std::vector<std::string> suitRepresentationM;
};

}

#endif
