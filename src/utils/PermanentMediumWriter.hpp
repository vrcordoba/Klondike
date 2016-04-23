#ifndef UTILS_PERMANENTMEDIUMWRITER_HPP_
#define UTILS_PERMANENTMEDIUMWRITER_HPP_

#include <string>

namespace Utils
{

class PermanentMediumWriter
{
public:
   virtual ~PermanentMediumWriter() {};

   virtual bool isOk() const = 0;
   virtual bool writeLine(std::string& line) = 0;
};

}

#endif
