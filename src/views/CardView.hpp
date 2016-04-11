#ifndef VIEWS_CARDVIEW_HPP_
#define VIEWS_CARDVIEW_HPP_

#include <string>

namespace Models
{
   class Card;
}

namespace Views
{

class CardView
{
public:
   virtual ~CardView() {};
   virtual void constructRepresentation() = 0;
   virtual std::string show(const Models::Card& card) const = 0;
};

}

#endif
