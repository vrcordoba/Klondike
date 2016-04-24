#ifndef UTILS_PERMANENTMEDIUMREADERPROTOTYPER_HPP_
#define UTILS_PERMANENTMEDIUMREADERPROTOTYPER_HPP_

#include <cstdint>
#include "PermanentMediumType.hpp"

namespace Utils
{

class PermanentMediumReader;

class PermanentMediumReaderPrototyper
{
public:
   PermanentMediumReaderPrototyper();
   ~PermanentMediumReaderPrototyper();

   static PermanentMediumReader* findAndClone(PermanentMediumType::Type type);
   static void addPrototype(PermanentMediumReader* medium);

private:
   static std::uint8_t nextSlotM;
   static PermanentMediumReader* prototypesM[PermanentMediumType::NUM_PERMANENT_MEDIUMS];
};

}

#endif
