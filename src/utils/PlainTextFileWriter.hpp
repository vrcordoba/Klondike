#ifndef UTILS_PLAINTEXTFILEWRITER_HPP_
#define UTILS_PLAINTEXTFILEWRITER_HPP_

#include <cstdint>
#include <fstream>
#include <string>
#include <list>
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
   void writeComposedField(const std::list<std::string>& fields);
   void writeNumericField(const std::int64_t number);

private:
   void writeFieldSeparator();

   std::ofstream fileM;
};

}

#endif
