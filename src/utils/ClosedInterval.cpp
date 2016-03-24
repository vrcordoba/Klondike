
#include "ClosedInterval.hpp"

#include <cassert>
#include <string>

namespace Utils
{

ClosedInterval::ClosedInterval(std::int64_t min, std::int64_t max)
   : minM(min), maxM(max)
{
   assert(min <= max);
}

ClosedInterval::~ClosedInterval()
{
}

bool ClosedInterval::includes(std::int64_t value) const
{
   return (value <= maxM) and (value >= minM);
}

std::string ClosedInterval::toString() const
{
   std::string text;
   text.append("[ ");
   text.append(std::to_string(minM));
   text.append(", ");
   text.append(std::to_string(maxM));
   text.append("]");
   return text;
}

}
