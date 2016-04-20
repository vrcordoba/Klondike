#ifndef MODELS_PILETYPE_HPP_
#define MODELS_PILETYPE_HPP_

#include <cstdint>

namespace Models
{

struct PileType
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
