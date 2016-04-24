#ifndef UTILS_PERMANENTMEDIUMPROTOTYPER_HPP_
#define UTILS_PERMANENTMEDIUMPROTOTYPER_HPP_

#include <cstdint>
#include "PermanentMediumType.hpp"

namespace Utils
{

class PermanentMediumReader;
class PermanentMediumWriter;

class PermanentMediumPrototyper
{
public:
   PermanentMediumPrototyper();
   ~PermanentMediumPrototyper();

   static PermanentMediumReader* getReader(PermanentMediumType::Type type);
   static PermanentMediumWriter* getWriter(PermanentMediumType::Type type);

   static void addReaderPrototype(PermanentMediumReader* medium);
   static void addWriterPrototype(PermanentMediumWriter* medium);

private:
   static std::int32_t readerSlotM;
   static std::int32_t writerSlotM;
   static PermanentMediumReader* readerPrototypesM[PermanentMediumType::NUM_PERMANENT_MEDIUMS];
   static PermanentMediumWriter* writerPrototypesM[PermanentMediumType::NUM_PERMANENT_MEDIUMS];
};

}

#endif
