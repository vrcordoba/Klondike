#ifndef UTILS_TEXTFILEREADER_HPP_
#define UTILS_TEXTFILEREADER_HPP_

#include <fstream>
#include <string>
#include "PermanentMediumReader.hpp"
#include "PermanentMediumType.hpp"

namespace Utils
{

class TextFileReader final : public PermanentMediumReader
{
public:
   TextFileReader();
   ~TextFileReader();

   TextFileReader(const TextFileReader&) = delete;
   TextFileReader& operator=(const TextFileReader&) = delete;

   Configuration::PermanentMediumType type();
   PermanentMediumReader* clone();

   void open(std::string name);
   bool isOk() const;
   bool getLine(std::string& line);

protected:
   explicit TextFileReader(std::uint8_t dummy);

private:
   std::ifstream fileM;
};

}

#endif
