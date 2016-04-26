
#include "PermanentMediumPrototyper.hpp"

#include <cassert>
#include <algorithm>
#include "PlainTextFileReader.hpp"
#include "PlainTextFileWriter.hpp"

namespace Utils
{

PermanentMediumPrototyper::PermanentMediumPrototyper()
{
   readerPrototypesM[PermanentMediumType::PLAIN_TEXT] = new PlainTextFileReader();
   writerPrototypesM[PermanentMediumType::PLAIN_TEXT] = new PlainTextFileWriter();
}

PermanentMediumPrototyper::~PermanentMediumPrototyper()
{
   std::for_each(std::begin(readerPrototypesM), std::end(readerPrototypesM),
      [] (std::pair<const PermanentMediumType, PermanentMediumReader*>& pair)
      {
         delete pair.second;
      });
   std::for_each(std::begin(writerPrototypesM), std::end(writerPrototypesM),
      [] (std::pair<const PermanentMediumType, PermanentMediumWriter*>& pair)
      {
         delete pair.second;
      });
}

PermanentMediumReader* PermanentMediumPrototyper::getReader(
   PermanentMediumType permanentMediumType)
{
   std::map<PermanentMediumType, PermanentMediumReader*>::const_iterator readerIt =
      readerPrototypesM.find(permanentMediumType);
   assert(readerIt != readerPrototypesM.end());
   PermanentMediumReader* permanentMediumReader = readerIt->second->clone();
   return permanentMediumReader;
}

PermanentMediumWriter* PermanentMediumPrototyper::getWriter(
   PermanentMediumType permanentMediumType)
{
   std::map<PermanentMediumType, PermanentMediumWriter*>::const_iterator writerIt =
      writerPrototypesM.find(permanentMediumType);
   assert(writerIt != writerPrototypesM.end());
   PermanentMediumWriter* permanentMediumWriter = writerIt->second->clone();
   return permanentMediumWriter;
}

}
