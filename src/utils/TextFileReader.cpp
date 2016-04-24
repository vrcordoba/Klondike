
#include "TextFileReader.hpp"

#include "PermanentMediumPrototyper.hpp"

namespace Utils
{

TextFileReader TextFileReader::textFileReaderM;

TextFileReader::TextFileReader() : fileM()
{
   PermanentMediumPrototyper::addReaderPrototype(this);
}

TextFileReader::TextFileReader(std::uint8_t dummy) : fileM()
{
}

TextFileReader::~TextFileReader()
{
   if (isOk())
      fileM.close();
}

PermanentMediumType::Type TextFileReader::type()
{
   return PermanentMediumType::Type::PLAIN_TEXT;
}

PermanentMediumReader* TextFileReader::clone()
{
   return new TextFileReader(1);
}

void TextFileReader::open(std::string name)
{
   fileM.open(name + ".txt");
}

bool TextFileReader::getLine(std::string& line)
{
   bool unreadLines = true;
   if (fileM.is_open() and (not fileM.eof()))
   {
      std::getline(fileM, line);
   }
   else
   {
      unreadLines = false;
   }
   return unreadLines;
}

bool TextFileReader::isOk() const
{
   return fileM.is_open();
}

}
