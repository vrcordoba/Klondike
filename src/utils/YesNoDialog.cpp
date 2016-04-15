
#include "YesNoDialog.hpp"

#include "IO.hpp"

namespace Utils
{

YesNoDialog::YesNoDialog(const std::string& title)
   : titleM(title + "? (y/n): ")
{
}

YesNoDialog::~YesNoDialog()
{
}

bool YesNoDialog::read() const
{
   char answer;
   bool isOk;
   do
   {
      IO& io = IO::getInstance();
      answer = io.readChar(titleM);
      isOk = (answer == 'y') || (answer == 'Y') || (answer == 'n')
         || (answer == 'N');
      if (!isOk)
      {
         io.writeString("Value must be 'y' or 'n'");
      }
   } while (!isOk);
   return (answer=='y') || (answer=='Y');
}

}
