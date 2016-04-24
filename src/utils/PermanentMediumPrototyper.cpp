
#include "PermanentMediumPrototyper.hpp"

#include "PermanentMediumReader.hpp"
#include "PermanentMediumWriter.hpp"

namespace Utils
{

PermanentMediumPrototyper::PermanentMediumPrototyper()
{
}

PermanentMediumPrototyper::~PermanentMediumPrototyper()
{
}

PermanentMediumReader* PermanentMediumPrototyper::readerPrototypesM[];
PermanentMediumWriter* PermanentMediumPrototyper::writerPrototypesM[];
std::int32_t PermanentMediumPrototyper::readerSlotM = 0;
std::int32_t PermanentMediumPrototyper::writerSlotM = 0;

void PermanentMediumPrototyper::addReaderPrototype(PermanentMediumReader* medium)
{
   readerPrototypesM[readerSlotM++] = medium;
}

void PermanentMediumPrototyper::addWriterPrototype(PermanentMediumWriter* medium)
{
   writerPrototypesM[writerSlotM++] = medium;
}

PermanentMediumReader* PermanentMediumPrototyper::getReader(
   PermanentMediumType::Type permanentMediumType)
{
  for (std::int32_t i = 0; i < readerSlotM; ++i)
    if (permanentMediumType == readerPrototypesM[i]->type())
      return readerPrototypesM[i]->clone();
  return nullptr;
}

PermanentMediumWriter* PermanentMediumPrototyper::getWriter(
   PermanentMediumType::Type permanentMediumType)
{
  for (std::int32_t i = 0; i < writerSlotM; ++i)
    if (permanentMediumType == writerPrototypesM[i]->type())
      return writerPrototypesM[i]->clone();
  return nullptr;
}

}
