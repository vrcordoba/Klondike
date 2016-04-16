#ifndef CONTROLLERS_LOCAL_MOVEMENTORIGINDESTINATIONTYPE_HPP_
#define CONTROLLERS_LOCAL_MOVEMENTORIGINDESTINATIONTYPE_HPP_

#include <cstdint>

namespace Controllers
{

struct MovementOriginDestinationType
{
   enum
   {
      WASTE,
      FOUNDATION,
      TABLEAU
   };
};

}

#endif
