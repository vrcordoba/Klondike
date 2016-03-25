
#include "SpanishCard.hpp"

namespace Models
{

SpanishCard::SpanishCard(std::uint16_t number, std::uint16_t suit)
   : Card(number, suit)
{
}

SpanishCard::~SpanishCard()
{
}

bool SpanishCard::isSameColor(const Card* const otherCard) const
{
   return Card::isSameSuit(otherCard);
}

}
