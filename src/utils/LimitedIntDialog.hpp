#ifndef UTILS_LIMITEDINTDIALOG_HPP_
#define UTILS_LIMITEDINTDIALOG_HPP_

#include <string>
#include <cstdint>
#include "ClosedInterval.hpp"

namespace Utils
{

class LimitedIntDialog final
{
public:
   LimitedIntDialog(const std::string& title, std::int64_t min, std::int64_t max);
   LimitedIntDialog(const std::string& title, std::int64_t max);
   ~LimitedIntDialog();

   LimitedIntDialog(const LimitedIntDialog&) = delete;
   LimitedIntDialog& operator=(const LimitedIntDialog&) = delete;

   std::int64_t read() const;

private:
   const ClosedInterval limitsM;
   const std::string titleM;
};

}

#endif
