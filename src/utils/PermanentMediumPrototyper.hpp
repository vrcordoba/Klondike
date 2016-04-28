#ifndef UTILS_PERMANENTMEDIUMPROTOTYPER_HPP_
#define UTILS_PERMANENTMEDIUMPROTOTYPER_HPP_

#include <cstdint>
#include <map>
#include "PermanentMedium.hpp"

namespace Utils
{

class PermanentMediumReader;
class PermanentMediumWriter;

class PermanentMediumPrototyper
{
public:
   PermanentMediumPrototyper();
   ~PermanentMediumPrototyper();

   PermanentMediumReader* getReader(PermanentMedium::Type type);
   PermanentMediumWriter* getWriter(PermanentMedium::Type type);

private:
   std::map<PermanentMedium::Type, PermanentMediumReader*> readerPrototypesM;
   std::map<PermanentMedium::Type, PermanentMediumWriter*> writerPrototypesM;
};

}

#endif
