#ifndef UTILS_PERMANENTMEDIUMREADER_HPP_
#define UTILS_PERMANENTMEDIUMREADER_HPP_

#include <cstdint>
#include <string>
#include <list>
#include "PermanentMedium.hpp"

namespace Utils
{

class PermanentMediumReader : public PermanentMedium
{
public:
   virtual ~PermanentMediumReader() {};

   virtual PermanentMediumReader* clone() = 0;

   virtual bool getField(std::string& line) = 0;
   virtual std::list<std::string> getComposedField() = 0;
   virtual std::int64_t getNumericField() = 0;
   virtual bool alreadyExists(const std::string& fileName) = 0;
};

}

#endif
