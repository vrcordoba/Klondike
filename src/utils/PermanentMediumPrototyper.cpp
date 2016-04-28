
#include "PermanentMediumPrototyper.hpp"

#include <cassert>
#include <algorithm>
#include "PlainTextFileReader.hpp"
#include "PlainTextFileWriter.hpp"

namespace Utils
{

PermanentMediumPrototyper::PermanentMediumPrototyper()
{
   readerPrototypesM.emplace(PermanentMedium::Type::PLAIN_TEXT, new PlainTextFileReader());
   writerPrototypesM.emplace(PermanentMedium::Type::PLAIN_TEXT, new PlainTextFileWriter());
}

PermanentMediumPrototyper::~PermanentMediumPrototyper()
{
   std::for_each(std::begin(readerPrototypesM), std::end(readerPrototypesM),
      [] (std::pair<const PermanentMedium::Type, PermanentMediumReader*>& pair)
      {
         delete pair.second;
      });
   std::for_each(std::begin(writerPrototypesM), std::end(writerPrototypesM),
      [] (std::pair<const PermanentMedium::Type, PermanentMediumWriter*>& pair)
      {
         delete pair.second;
      });
}

PermanentMediumReader* PermanentMediumPrototyper::getReader(
   PermanentMedium::Type permanentMediumType)
{
   std::map<PermanentMedium::Type, PermanentMediumReader*>::const_iterator readerIt =
      readerPrototypesM.find(permanentMediumType);
   assert(readerIt != readerPrototypesM.end());
   PermanentMediumReader* permanentMediumReader = readerIt->second->clone();
   return permanentMediumReader;
}

PermanentMediumWriter* PermanentMediumPrototyper::getWriter(
   PermanentMedium::Type permanentMediumType)
{
   std::map<PermanentMedium::Type, PermanentMediumWriter*>::const_iterator writerIt =
      writerPrototypesM.find(permanentMediumType);
   assert(writerIt != writerPrototypesM.end());
   PermanentMediumWriter* permanentMediumWriter = writerIt->second->clone();
   return permanentMediumWriter;
}

}
