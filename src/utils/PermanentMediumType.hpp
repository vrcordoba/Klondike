#ifndef UTILS_PERMANENTMEDIUMTYPE_HPP_
#define UTILS_PERMANENTMEDIUMTYPE_HPP_

#include <cstdint>

namespace Utils
{

class PermanentMediumType
{
public:
   enum Type
   {
      PLAIN_TEXT
   };

   static const std::uint8_t NUM_PERMANENT_MEDIUMS = 1;
};
};

#endif
