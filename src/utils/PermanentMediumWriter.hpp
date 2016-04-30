#ifndef UTILS_PERMANENTMEDIUMWRITER_HPP_
#define UTILS_PERMANENTMEDIUMWRITER_HPP_

#include <string>
#include <list>
#include "PermanentMedium.hpp"

namespace Utils
{

class PermanentMediumWriter : public PermanentMedium
{
public:
   virtual ~PermanentMediumWriter() {};

   virtual PermanentMediumWriter* clone() = 0;

   virtual void writeField(const std::string& field) = 0;
   virtual void writeComposedField(const std::list<std::string>& fields) = 0;
   virtual void writeNumericField(const std::int64_t number) = 0;
};

}

#endif
