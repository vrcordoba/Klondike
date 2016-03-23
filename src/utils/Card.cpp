
#include "Card.hpp"

namespace Utils
{

Card::Card(std::uint16_t number, std::uint16_t suit)
   : numberM(number), suitM(suit)
{
}

Card::~Card()
{
}

Card& Card::operator=(const Card& otherCard)
{
   numberM = otherCard.numberM;
   suitM = otherCard.suitM;
   return *this;
}

bool Card::operator==(const Card& otherCard) const
{
   return (numberM == otherCard.numberM) and (suitM == otherCard.suitM);
}

bool Card::isSameSuit(const Card& otherCard) const
{
   return suitM == otherCard.suitM;
}

bool Card::isOneAbove(const Card& otherCard) const
{
   return numberM == (otherCard.numberM + 1);
}

bool Card::isOneBelow(const Card& otherCard) const
{
   return numberM == (otherCard.numberM - 1);
}

}
