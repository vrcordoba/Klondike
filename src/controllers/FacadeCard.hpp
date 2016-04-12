#ifndef CONTROLLERS_FACADECARD_HPP_
#define CONTROLLERS_FACADECARD_HPP_

#include <cstdint>

namespace Models
{
   class Card;
}

namespace Controllers
{

class FacadeCard
{
public:
   explicit FacadeCard(const Models::Card& card);
   ~FacadeCard();

   std::uint8_t getNumber() const;
   std::uint8_t getSuit() const;
   std::uint8_t getColor() const;
   bool isUpturned() const;

private:
   std::uint8_t numberM;
   std::uint8_t suitM;
   bool upturnedM;
};

}

#endif
