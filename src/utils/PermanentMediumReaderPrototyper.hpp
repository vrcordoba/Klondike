#ifndef UTILS_PERMANENTMEDIUMREADERPROTOTYPER_HPP_
#define UTILS_PERMANENTMEDIUMREADERPROTOTYPER_HPP_

#include <cstdint>

namespace Utils
{

class PermanentMediumReader;

class PermanentMediumReaderPrototyper
{
public:
   PermanentMediumReaderPrototyper();
   ~PermanentMediumReaderPrototyper();

   enum
   {
      PLAIN_TEXT
   };

   static PermanentMediumReader* makePrototype(std::uint8_t prototype);

private:
   static const std::uint8_t NUM_READER_TYPES = 1;
   static PermanentMediumReader* prototypes[NUM_READER_TYPES];
};

}

#endif
