
#include "TextFileReader.hpp"

namespace Utils
{

TextFileReader::TextFileReader() : fileM()
{
}

TextFileReader::~TextFileReader()
{
   fileM.close();
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
