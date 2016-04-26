#ifndef UTILS_PLAINTEXTFILEREADER_HPP_
#define UTILS_PLAINTEXTFILEREADER_HPP_

#include <fstream>
#include <string>
#include "PermanentMediumReader.hpp"

namespace Utils
{

class PlainTextFileReader final : public PermanentMediumReader
{
public:
   PlainTextFileReader();
   ~PlainTextFileReader();

   PlainTextFileReader(const PlainTextFileReader&) = delete;
   PlainTextFileReader& operator=(const PlainTextFileReader&) = delete;

   PermanentMediumReader* clone();

   void open(std::string name);
   bool isOk() const;
   bool getLine(std::string& line);

private:
   std::ifstream fileM;
};

}

#endif
