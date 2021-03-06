#ifndef MODELS_CARD_HPP_
#define MODELS_CARD_HPP_

#include <cstdint>
#include <string>
#include "Suit.hpp"

namespace Models
{

class Card final
{
public:
   Card(std::uint8_t number = 0, Suit suit = Suit(0, 0), bool upturned = false);
   ~Card();

   Card& operator=(const Card& otherCard);
   bool operator==(const Card& otherCard) const;

   bool isUpturned() const;
   void setUpturned(bool upturned);

   bool isSameColor(const Card& otherCard) const;
   bool isSameSuit(const Card& otherCard) const;
   bool isOneAbove(const Card& otherCard) const;
   bool isOneBelow(const Card& otherCard) const;

   std::uint8_t getNumber() const;
   std::uint8_t getSuit() const;

   std::string toString() const;
   void fromString(std::string cardStr);

private:
   std::uint8_t numberM;
   Suit suitM;
   bool upturnedM;
};

}

#endif
