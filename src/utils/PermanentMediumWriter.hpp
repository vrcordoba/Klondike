#ifndef UTILS_PERMANENTMEDIUMWRITER_HPP_
#define UTILS_PERMANENTMEDIUMWRITER_HPP_

#include <string>
#include "PermanentMediumType.hpp"

namespace Utils
{

class PermanentMediumWriter
{
public:
   virtual ~PermanentMediumWriter() {};

   virtual Configuration::PermanentMediumType type() = 0;
   virtual PermanentMediumWriter* clone() = 0;

   virtual void open(const std::string& name) = 0;
   virtual bool isOk() const = 0;
   virtual void writeLine(const std::string& line) = 0;
};

}

#endif
