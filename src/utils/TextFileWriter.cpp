
#include "TextFileWriter.hpp"

#include "PermanentMediumPrototyper.hpp"

namespace Utils
{

TextFileWriter TextFileWriter::textFileWriterM;

TextFileWriter::TextFileWriter() : fileM()
{
   PermanentMediumPrototyper::addWriterPrototype(this);
}

TextFileWriter::TextFileWriter(std::uint8_t dummy) : fileM()
{
}

TextFileWriter::~TextFileWriter()
{
   if (isOk())
      fileM.close();
}

PermanentMediumType::Type TextFileWriter::type()
{
   return PermanentMediumType::Type::PLAIN_TEXT;
}

PermanentMediumWriter* TextFileWriter::clone()
{
   return new TextFileWriter(1);
}

void TextFileWriter::open(const std::string& name)
{
   fileM.open(name + ".txt");
}

void TextFileWriter::writeLine(const std::string& line)
{
   fileM << line << std::endl;
}

bool TextFileWriter::isOk() const
{
   return fileM.is_open();
}

}
