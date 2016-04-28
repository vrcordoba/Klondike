#ifndef UTILS_PLAINTEXTFILEWRITER_HPP_
#define UTILS_PLAINTEXTFILEWRITER_HPP_

#include <fstream>
#include <string>
#include "PermanentMediumWriter.hpp"

namespace Utils
{

class PlainTextFileWriter final : public PermanentMediumWriter
{
public:
   PlainTextFileWriter();
   ~PlainTextFileWriter();

   PlainTextFileWriter(const PlainTextFileWriter&) = delete;
   PlainTextFileWriter& operator=(const PlainTextFileWriter&) = delete;

   PermanentMediumWriter* clone();

   void open(const std::string& name);
   bool isOk() const;
   void writeField(const std::string& line);
   void writeFieldSeparator();

private:
   std::ofstream fileM;
};

}

#endif
