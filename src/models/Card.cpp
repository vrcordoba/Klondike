
#include "Card.hpp"

namespace Models
{

Card::Card(std::uint8_t number, Suit suit, bool upturned)
   : numberM(number), suitM(suit), upturnedM(upturned)
{
}

Card::~Card()
{
}

Card& Card::operator=(const Card& otherCard)
{
   numberM = otherCard.numberM;
   suitM = otherCard.suitM;
   upturnedM = otherCard.upturnedM;
   return *this;
}

bool Card::operator==(const Card& otherCard) const
{
   return (numberM == otherCard.numberM) and (suitM == otherCard.suitM);
}

bool Card::isUpturned() const
{
   return upturnedM;
}

void Card::setUpturned(bool upturned)
{
   upturnedM = upturned;
}

bool Card::isSameSuit(const Card& otherCard) const
{
   return suitM.sameSuit(otherCard.suitM);
}

bool Card::isSameColor(const Card& otherCard) const
{
   return suitM.sameColor(otherCard.suitM);
}

bool Card::isOneAbove(const Card& otherCard) const
{
   return numberM == (otherCard.numberM + 1);
}

bool Card::isOneBelow(const Card& otherCard) const
{
   return numberM == (otherCard.numberM - 1);
}

std::uint8_t Card::getNumber() const
{
   return numberM;
}

std::uint8_t Card::getSuit() const
{
   return suitM.getSuit();
}

std::string Card::toString() const
{
   return std::to_string(numberM) + " " + std::to_string(upturnedM) +
      " " + suitM.toString();
}

}
