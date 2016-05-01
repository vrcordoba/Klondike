
#include "Card.hpp"

#include <cassert>
#include <sstream>
#include <iterator>
#include <vector>
#include <limits>

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

void Card::fromString(std::string cardStr)
{
   std::istringstream iss(cardStr);
   std::vector<std::string> tokenizedCard{std::istream_iterator<std::string>{iss},
      std::istream_iterator<std::string>{}};
   assert(4 == tokenizedCard.size());
   numberM = std::stoi(tokenizedCard[0]);
   upturnedM = std::stoi(tokenizedCard[1]);
   suitM.fromString(tokenizedCard[2], tokenizedCard[3]);
}

}
