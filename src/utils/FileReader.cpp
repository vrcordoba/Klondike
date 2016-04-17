
#include "FileReader.hpp"

namespace Utils
{

FileReader::FileReader(std::string fileName) : fileM(fileName)
{
}

FileReader::~FileReader()
{
   fileM.close();
}

bool FileReader::getLine(std::string& line)
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

bool FileReader::isOk() const
{
   return fileM.is_open();
}

}
