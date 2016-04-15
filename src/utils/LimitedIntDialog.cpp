
#include "LimitedIntDialog.hpp"

#include "IO.hpp"

namespace Utils
{

LimitedIntDialog::LimitedIntDialog(const std::string& title, std::int64_t min,
   std::int64_t max) : limitsM(min, max),
   titleM(title + " " + limitsM.toString() + ": ")
{
}

LimitedIntDialog::LimitedIntDialog(const std::string& title, std::int64_t max)
   : LimitedIntDialog(title, 1, max)
{
}

LimitedIntDialog::~LimitedIntDialog()
{
}

std::int64_t LimitedIntDialog::read() const
{
   IO& io = IO::getInstance();
   int value;
   bool isOk;
   do
   {
      value = io.readInt(titleM);
      isOk = limitsM.includes(value);
      if (!isOk)
      {
         io.writeString("Value must be between " + limitsM.toString());
      }
   } while (!isOk);
   return value;
}

}
