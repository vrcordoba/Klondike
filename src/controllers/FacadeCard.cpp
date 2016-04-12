
#include "FacadeCard.hpp"
#include "Card.hpp"

namespace Controllers
{

FacadeCard::FacadeCard(const Models::Card& card) : numberM(card.getNumber()),
   suitM(card.getSuit()), upturnedM(card.isUpturned())
{
}

FacadeCard::~FacadeCard()
{
}

std::uint8_t FacadeCard::getNumber() const
{
   return numberM;
}

std::uint8_t FacadeCard::getSuit() const
{
   return suitM;
}

bool FacadeCard::isUpturned() const
{
   return upturnedM;
}

}
