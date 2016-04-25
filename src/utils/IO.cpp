
#include <IO.hpp>

#include <iostream>
#include <sstream>
#include <limits>

namespace Utils
{

IO::IO()
{
}

IO::~IO()
{
}

std::string IO::readString(const std::string& title) const
{
   writeString(title);
   std::string read;
   std::getline(std::cin, read);
   return read;
}

std::int64_t IO::readInt(const std::string& title) const
{
   std::int64_t readInt;
   bool isOk = false;
   do
   {
      std::string readStr = readString(title);
      std::istringstream converter(readStr);
      if (converter >> readInt)
      {
         isOk = true;
      }
      else
      {
         writeError("Integer");
      }
   }
   while(not(isOk));
   return readInt;
}

char IO::readChar(const std::string& title) const
{
   writeString(title);
   char readChar;
   std::cin.get(readChar);
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   return readChar;
}

void IO::writeError(const std::string& format) const
{
   writeString("Format error! Write a/an " + format);
}

void IO::writeString(const std::string& text) const
{
   writeStringNotEndingLine(text);
   std::cout << std::endl;
}

void IO::writeStringNotEndingLine(const std::string& text) const
{
   std::cout << text;
}

}
