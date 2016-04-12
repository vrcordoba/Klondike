
#include "CardTextView.hpp"

#include "Card.hpp"
#include "IO.hpp"
#include "FacadeCard.hpp"

namespace Views
{

CardTextView::~CardTextView()
{
}

std::string CardTextView::show(const Controllers::FacadeCard& card) const
{
   std::string cardRepresentation;
   if (not card.isUpturned())
   {
      cardRepresentation = "[";
   }
   else
   {
      std::uint8_t number = card.getNumber();
      std::uint8_t suit = card.getSuit();
      cardRepresentation = "[" + numberRepresentationM[number] + ", " + suitRepresentationM[suit] + "]";
   }
   return cardRepresentation;
}

}
