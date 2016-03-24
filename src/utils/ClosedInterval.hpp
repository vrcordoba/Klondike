#ifndef UTILS_CLOSEDINTERVAL_HPP_
#define UTILS_CLOSEDINTERVAL_HPP_

#include <cstdint>
#include <string>

namespace Utils
{

class ClosedInterval final
{
public:
   ClosedInterval(std::int64_t min, std::int64_t max);
   ~ClosedInterval();

   ClosedInterval(const ClosedInterval&) = delete;
   ClosedInterval& operator=(const ClosedInterval&) = delete;

   bool includes(std::int64_t value) const;
   std::string toString() const;

private:
   std::int64_t minM;
   std::int64_t maxM;
};

}

#endif
