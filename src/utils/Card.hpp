#ifndef UTILS_CARD_HPP_
#define UTILS_CARD_HPP_

#include <cstdint>

namespace Utils
{

class Card final
{
public:
   Card(std::uint16_t number, std::uint16_t suit);
   ~Card();

   Card& operator=(const Card&);
   bool operator==(const Card&) const;

   bool isSameSuit(const Card&) const;
   bool isOneAbove(const Card&) const;
   bool isOneBelow(const Card&) const;

private:
   std::uint16_t numberM;
   std::uint16_t suitM;
};

}

#endif
