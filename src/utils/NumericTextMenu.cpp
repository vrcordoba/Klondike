
#include "NumericTextMenu.hpp"

#include "IO.hpp"
#include "LimitedIntDialog.hpp"

namespace Utils
{

NumericTextMenu::NumericTextMenu(const std::string& title) : titleM(title), optionsM()
{
}

NumericTextMenu::~NumericTextMenu()
{
}

void NumericTextMenu::show() const
{
   IO& io = IO::getInstance();
   io.writeString(titleM);
   std::uint8_t optionIndex = 1;
   for (auto option : optionsM)
   {
      io.writeString(std::to_string(optionIndex++) + " - " + option);
   }
}

std::int64_t NumericTextMenu::read() const
{
   return LimitedIntDialog("Choose option", optionsM.size()).read();
}

void NumericTextMenu::addOption(const std::string& option)
{
   optionsM.push_back(option);
}

}
