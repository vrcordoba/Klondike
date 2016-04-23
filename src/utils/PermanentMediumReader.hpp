#ifndef UTILS_PERMANENTMEDIUMREADER_HPP_
#define UTILS_PERMANENTMEDIUMREADER_HPP_

#include <string>

namespace Utils
{

class PermanentMediumReader
{
public:
   virtual ~PermanentMediumReader() {};

   virtual void open(std::string name) = 0;
   virtual bool isOk() const = 0;
   virtual bool getLine(std::string& line) = 0;
};

}

#endif
