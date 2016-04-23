
#include "PermanentMediumReaderPrototyper.hpp"

#include <cassert>
#include "PermanentMediumReader.hpp"
#include "TextFileReader.hpp"

namespace Utils
{

PermanentMediumReaderPrototyper::PermanentMediumReaderPrototyper()
{
}

PermanentMediumReaderPrototyper::~PermanentMediumReaderPrototyper()
{
}

PermanentMediumReader* PermanentMediumReaderPrototyper::prototypes[] = {new TextFileReader()};

PermanentMediumReader* PermanentMediumReaderPrototyper::makePrototype(std::uint8_t prototype)
{
   assert(prototype < NUM_READER_TYPES);
   return prototypes[prototype];
}

}
