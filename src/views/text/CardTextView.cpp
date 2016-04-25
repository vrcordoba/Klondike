
#include "CardTextView.hpp"

#include "IO.hpp"
#include "FacadeCard.hpp"

namespace Views
{

CardTextView::~CardTextView()
{
}

void CardTextView::show(const Controllers::FacadeCard& card) const
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
      cardRepresentation = "[" + suitRepresentationM[suit] + ", " +
         numberRepresentationM[number] + "\033[39;49m]";
   }
   Utils::IO::getInstance().writeStringNotEndingLine(cardRepresentation);
}

}
