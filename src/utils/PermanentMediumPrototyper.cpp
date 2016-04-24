
#include "PermanentMediumPrototyper.hpp"

#include <cassert>
#include "TextFileReader.hpp"
#include "TextFileWriter.hpp"

namespace Utils
{

PermanentMediumPrototyper::PermanentMediumPrototyper()
{
   readerPrototypesM[Configuration::PermanentMediumType::PLAIN_TEXT] = new TextFileReader();
   writerPrototypesM[Configuration::PermanentMediumType::PLAIN_TEXT] = new TextFileWriter();
}

PermanentMediumPrototyper::~PermanentMediumPrototyper()
{
}

PermanentMediumReader* PermanentMediumPrototyper::getReader(
   Configuration::PermanentMediumType permanentMediumType)
{
   std::map<Configuration::PermanentMediumType, PermanentMediumReader*>::const_iterator readerIt =
      readerPrototypesM.find(permanentMediumType);
   assert(readerIt != readerPrototypesM.end());
   PermanentMediumReader* permanentMediumReader = readerIt->second->clone();
   return permanentMediumReader;
}

PermanentMediumWriter* PermanentMediumPrototyper::getWriter(
   Configuration::PermanentMediumType permanentMediumType)
{
   std::map<Configuration::PermanentMediumType, PermanentMediumWriter*>::const_iterator writerIt =
      writerPrototypesM.find(permanentMediumType);
   assert(writerIt != writerPrototypesM.end());
   PermanentMediumWriter* permanentMediumWriter = writerIt->second->clone();
   return permanentMediumWriter;
}

}
