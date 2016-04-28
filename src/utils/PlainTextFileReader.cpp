
#include "PlainTextFileReader.hpp"

namespace Utils
{

PlainTextFileReader::PlainTextFileReader() : fileM()
{
}

PlainTextFileReader::~PlainTextFileReader()
{
   if (isOk())
      fileM.close();
}

PermanentMediumReader* PlainTextFileReader::clone()
{
   return new PlainTextFileReader();
}

void PlainTextFileReader::open(const std::string& name)
{
   fileM.open(name + ".txt");
}

bool PlainTextFileReader::getField(std::string& line)
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

bool PlainTextFileReader::isOk() const
{
   return fileM.is_open();
}

bool PlainTextFileReader::alreadyExists(const std::string& fileName)
{
   open(fileName);
   return isOk();
}

}
