#ifndef UTILS_YESNODIALOG_HPP_
#define UTILS_YESNODIALOG_HPP_

#include <string>

namespace Utils
{

class YesNoDialog final
{
public:
   explicit YesNoDialog(const std::string& title);
   ~YesNoDialog();

   YesNoDialog(const YesNoDialog&) = delete;
   YesNoDialog& operator=(const YesNoDialog&) = delete;

   bool read() const;

private:
   std::string titleM;
};

}

#endif
