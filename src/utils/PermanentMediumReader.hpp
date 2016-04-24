#ifndef UTILS_PERMANENTMEDIUMREADER_HPP_
#define UTILS_PERMANENTMEDIUMREADER_HPP_

#include <string>
#include "PermanentMediumType.hpp"

namespace Utils
{

class PermanentMediumReader
{
public:
   virtual ~PermanentMediumReader() {};

   virtual Configuration::PermanentMediumType type() = 0;
   virtual PermanentMediumReader* clone() = 0;

   virtual void open(std::string name) = 0;
   virtual bool isOk() const = 0;
   virtual bool getLine(std::string& line) = 0;
};

}

#endif
