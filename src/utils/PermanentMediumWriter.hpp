#ifndef UTILS_PERMANENTMEDIUMWRITER_HPP_
#define UTILS_PERMANENTMEDIUMWRITER_HPP_

#include <string>
#include "PermanentMedium.hpp"

namespace Utils
{

class PermanentMediumWriter : public PermanentMedium
{
public:
   virtual ~PermanentMediumWriter() {};

   virtual PermanentMediumWriter* clone() = 0;

   virtual void writeField(const std::string& line) = 0;
   virtual void writeFieldSeparator() = 0;
};

}

#endif
