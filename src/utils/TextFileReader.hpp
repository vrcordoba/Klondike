#ifndef UTILS_TEXTFILEREADER_HPP_
#define UTILS_TEXTFILEREADER_HPP_

#include <fstream>
#include <string>
#include "PermanentMediumReader.hpp"

namespace Utils
{

class TextFileReader final : public PermanentMediumReader
{
public:
   TextFileReader();
   ~TextFileReader();

   TextFileReader(const TextFileReader&) = delete;
   TextFileReader& operator=(const TextFileReader&) = delete;

   void open(std::string name);
   bool isOk() const;
   bool getLine(std::string& line);

private:
   std::ifstream fileM;
};

}

#endif
