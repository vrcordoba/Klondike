
#include "Suit.hpp"

namespace Models
{

Suit::Suit(std::uint8_t suit, std::uint8_t color) : suitM(suit), colorM(color)
{
}

Suit::~Suit()
{
}

bool Suit::operator==(const Suit& otherSuit) const
{
   return (sameSuit(otherSuit) and sameColor(otherSuit));
}

bool Suit::sameSuit(const Suit& otherSuit) const
{
   return suitM == otherSuit.suitM;
}

bool Suit::sameColor(const Suit& otherSuit) const
{
   return colorM == otherSuit.colorM;
}

std::uint8_t Suit::getSuit() const
{
   return suitM;
}

std::string Suit::toString() const
{
   return std::to_string(suitM) + " " + std::to_string(colorM);
}

void Suit::fromString(std::string suitStr, std::string colorStr)
{
   suitM = std::stoi(suitStr);
   colorM = std::stoi(colorStr);
}

}
