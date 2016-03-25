#ifndef MODELS_SPANISHCARD_HPP_
#define MODELS_SPANISHCARD_HPP_

#include "Card.hpp"
#include <cstdint>

namespace Models
{

class SpanishCard final: public Card
{
public:
   SpanishCard(std::uint16_t number, std::uint16_t suit);
   ~SpanishCard();

   SpanishCard(const SpanishCard&) = delete;
   SpanishCard& operator=(const SpanishCard&) = delete;

   bool isSameColor(const Card* const otherCard) const;
};

}

#endif
