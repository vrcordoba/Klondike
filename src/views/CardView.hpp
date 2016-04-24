#ifndef VIEWS_CARDVIEW_HPP_
#define VIEWS_CARDVIEW_HPP_

#include <string>
#include "DeckType.hpp"

namespace Controllers
{
class FacadeCard;
}

namespace Views
{

class CardView
{
public:
   virtual ~CardView() {};

   virtual Configuration::DeckType::Type type() = 0;
   virtual CardView* clone() = 0;

   virtual void constructRepresentation() = 0;
   virtual std::string show(const Controllers::FacadeCard& card) const = 0;
};

}

#endif
