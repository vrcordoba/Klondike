#ifndef UTILS_FILEREADER_HPP_
#define UTILS_FILEREADER_HPP_

#include <fstream>
#include <string>

namespace Utils
{

class FileReader final
{
public:
   explicit FileReader(std::string fileName);
   ~FileReader();

   FileReader(const FileReader&) = delete;
   FileReader& operator=(const FileReader&) = delete;

   bool isOk() const;
   bool getLine(std::string& line);

private:
   std::ifstream fileM;
};

}

#endif
