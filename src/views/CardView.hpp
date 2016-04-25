#ifndef VIEWS_CARDVIEW_HPP_
#define VIEWS_CARDVIEW_HPP_

#include <string>

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

   virtual CardView* clone() = 0;

   virtual void constructRepresentation() = 0;
   virtual void show(const Controllers::FacadeCard& card) const = 0;
};

}

#endif
