#ifndef UTILS_TEXTFILEWRITER_HPP_
#define UTILS_TEXTFILEWRITER_HPP_

#include <fstream>
#include <string>
#include "PermanentMediumWriter.hpp"
#include "PermanentMediumType.hpp"

namespace Utils
{

class TextFileWriter final : public PermanentMediumWriter
{
public:
   ~TextFileWriter();

   TextFileWriter(const TextFileWriter&) = delete;
   TextFileWriter& operator=(const TextFileWriter&) = delete;

   PermanentMediumType::Type type();
   PermanentMediumWriter* clone();

   void open(std::string name);
   bool isOk() const;
   void writeLine(const std::string line);

protected:
   explicit TextFileWriter(std::uint8_t dummy);

private:
   TextFileWriter();

   static TextFileWriter textFileWriterM;
   std::ofstream fileM;
};

}

#endif
