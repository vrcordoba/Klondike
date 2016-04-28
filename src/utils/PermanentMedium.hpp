#ifndef UTILS_PERMANENTMEDIUM_HPP_
#define UTILS_PERMANENTMEDIUM_HPP_

#include <cstdint>

namespace Utils
{

class PermanentMedium
{
public:
   virtual ~PermanentMedium() {};

   virtual void open(const std::string& name) = 0;
   virtual bool isOk() const = 0;

   enum class Type : std::uint8_t
   {
      PLAIN_TEXT
   };

protected:
   const std::string FIELD_SEPARATOR = "========";

};

}

#endif
