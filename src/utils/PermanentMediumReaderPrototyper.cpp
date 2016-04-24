
#include "PermanentMediumReaderPrototyper.hpp"

#include "PermanentMediumReader.hpp"

namespace Utils
{

PermanentMediumReaderPrototyper::PermanentMediumReaderPrototyper()
{
}

PermanentMediumReaderPrototyper::~PermanentMediumReaderPrototyper()
{
}

PermanentMediumReader* PermanentMediumReaderPrototyper::prototypesM[];
std::uint8_t PermanentMediumReaderPrototyper::nextSlotM;

void PermanentMediumReaderPrototyper::addPrototype(PermanentMediumReader* medium)
{
   prototypesM[nextSlotM++] = medium;
}

PermanentMediumReader* PermanentMediumReaderPrototyper::findAndClone(
   PermanentMediumType::Type permanentMediumType)
{
  for (int i = 0; i < nextSlotM; i++)
    if (permanentMediumType == prototypesM[i]->type())
      return prototypesM[i]->clone();
  return nullptr;
}

}
