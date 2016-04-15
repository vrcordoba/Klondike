#ifndef UTILS_IO_HPP_
#define UTILS_IO_HPP_

#include <string>
#include <cstdint>

namespace Utils
{

class IO final
{
public:
   ~IO();

   static IO& getInstance()
   {
      static IO instance;
      return instance;
   }

   IO(const IO&) = delete;
   IO& operator=(const IO&) = delete;

   std::string readString(const std::string& title) const;
   std::int64_t readInt(const std::string& title) const;
   char readChar(const std::string& title) const;

   void writeString(const std::string& text) const;

private:
   IO();
   void writeError(const std::string& format) const;
};

}

#endif
