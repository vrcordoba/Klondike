#ifndef UTILS_PLAINTEXTFILEREADER_HPP_
#define UTILS_PLAINTEXTFILEREADER_HPP_

#include <fstream>
#include <cstdint>
#include <list>
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

   void open(const std::string& name);
   bool isOk() const;
   bool getField(std::string& line);
   std::list<std::string> getComposedField();
   std::int64_t getNumericField();
   bool alreadyExists(const std::string& fileName);

private:
   std::ifstream fileM;
};

}

#endif
