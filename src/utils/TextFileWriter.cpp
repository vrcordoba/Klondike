
#include "TextFileWriter.hpp"

namespace Utils
{

TextFileWriter::TextFileWriter(std::string& fileName) : fileM(fileName)
{
}

TextFileWriter::~TextFileWriter()
{
   fileM.close();
}

void TextFileWriter::writeLine(const std::string& line)
{
   fileM << line;
}

bool TextFileWriter::isOk() const
{
   return fileM.is_open();
}

}
