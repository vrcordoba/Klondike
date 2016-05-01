
#include "PlainTextFileReader.hpp"

#include <limits>

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

std::list<std::string> PlainTextFileReader::getComposedField()
{
   std::list<std::string> composedField;
   std::string readLine;
   getField(readLine);
   while (0 != readLine.compare(FIELD_SEPARATOR))
   {
      composedField.push_back(readLine);
      getField(readLine);
   }
   return composedField;
}

std::int64_t PlainTextFileReader::getNumericField()
{
   std::string readLine;
   getField(readLine);
   std::int64_t readInt;
   try
   {
      readInt = std::stoi(readLine);
   }
   catch (const std::exception& e)
   {
      readInt = std::numeric_limits<std::int64_t>::quiet_NaN();
   }
   return readInt;
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
