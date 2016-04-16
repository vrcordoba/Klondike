
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

std::string FileReader::getLine()
{
   std::string line;
   if (fileM.is_open() and fileM.eof())
   {
      std::getline(fileM, line);
   }
   return line;
}

}
