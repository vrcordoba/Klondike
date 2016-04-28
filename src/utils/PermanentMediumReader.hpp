#ifndef UTILS_PERMANENTMEDIUMREADER_HPP_
#define UTILS_PERMANENTMEDIUMREADER_HPP_

#include <string>
#include "PermanentMedium.hpp"

namespace Utils
{

class PermanentMediumReader : public PermanentMedium
{
public:
   virtual ~PermanentMediumReader() {};

   virtual PermanentMediumReader* clone() = 0;

   virtual bool getField(std::string& line) = 0;
   virtual bool alreadyExists(const std::string& fileName) = 0;
};

}

#endif
