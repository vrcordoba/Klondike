#ifndef MODELS_MOVEMENTORIGINDESTINATIONTYPE_HPP_
#define MODELS_MOVEMENTORIGINDESTINATIONTYPE_HPP_

#include <cstdint>

namespace Models
{

struct MovementOriginDestinationType
{
   enum
   {
      DECK,
      WASTE,
      FOUNDATION,
      TABLEAU
   };
};

}

#endif
