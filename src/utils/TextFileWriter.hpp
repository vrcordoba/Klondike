#ifndef UTILS_TEXTFILEWRITER_HPP_
#define UTILS_TEXTFILEWRITER_HPP_

#include <fstream>
#include <string>

namespace Utils
{

class TextFileWriter final : public PermanentMediumWriter
{
public:
   explicit TextFileWriter(std::string& fileName);
   ~TextFileWriter();

   TextFileWriter(const TextFileWriter&) = delete;
   TextFileWriter& operator=(const TextFileWriter&) = delete;

   bool isOk() const;
   void writeLine(const std::string& line);

private:
   std::ofstream fileM;
};

}

#endif
