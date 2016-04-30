#ifndef MODELS_SUIT_HPP_
#define MODELS_SUIT_HPP_

#include <cstdint>
#include <vector>
#include <string>

namespace Models
{

class Suit final
{
public:
   Suit(std::uint8_t suit, std::uint8_t color);
   ~Suit();

   bool operator==(const Suit& otherSuit) const;

   bool sameSuit(const Suit& otherSuit) const;
   bool sameColor(const Suit& otherSuit) const;

   std::uint8_t getSuit() const;

   std::string toString() const;
   void fromString(std::string suitStr, std::string colorStr);

private:
   std::uint8_t suitM;
   std::uint8_t colorM;
};

}

#endif
