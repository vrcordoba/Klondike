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

   PermanentMediumReader* getReader(Configuration::PermanentMediumType type);
   PermanentMediumWriter* getWriter(Configuration::PermanentMediumType type);

private:
   std::map<Configuration::PermanentMediumType, PermanentMediumReader*> readerPrototypesM;
   std::map<Configuration::PermanentMediumType, PermanentMediumWriter*> writerPrototypesM;
};

}

#endif
