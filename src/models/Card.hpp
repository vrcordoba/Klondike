#ifndef MODELS_CARD_HPP_
#define MODELS_CARD_HPP_

#include <cstdint>

namespace Models
{

class Card
{
public:
   Card(std::uint16_t number, std::uint16_t suit);
   virtual ~Card();

   Card& operator=(const Card& otherCard);
   bool operator==(const Card& otherCard) const;

   virtual bool isSameColor(const Card* const otherCard) const = 0;
   virtual bool isSameSuit(const Card* const otherCard) const;
   virtual bool isOneAbove(const Card* const otherCard) const;
   virtual bool isOneBelow(const Card* const otherCard) const;

protected:
   std::uint16_t numberM;
   std::uint16_t suitM;
};

}

#endif
