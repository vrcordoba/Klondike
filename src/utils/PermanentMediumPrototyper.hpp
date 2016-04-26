#ifndef UTILS_PERMANENTMEDIUMPROTOTYPER_HPP_
#define UTILS_PERMANENTMEDIUMPROTOTYPER_HPP_

#include <cstdint>
#include <map>
#include "PermanentMediumType.hpp"
#include "PermanentMediumReader.hpp"
#include "PermanentMediumWriter.hpp"

namespace Utils
{

class PermanentMediumReader;
class PermanentMediumWriter;

class PermanentMediumPrototyper
{
public:
   PermanentMediumPrototyper();
   ~PermanentMediumPrototyper();

   PermanentMediumReader* getReader(PermanentMediumType type);
   PermanentMediumWriter* getWriter(PermanentMediumType type);

private:
   std::map<PermanentMediumType, PermanentMediumReader*> readerPrototypesM;
   std::map<PermanentMediumType, PermanentMediumWriter*> writerPrototypesM;
};

}

#endif
