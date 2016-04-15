
#include "TextMenu.hpp"

#include "IO.hpp"
#include "LimitedIntDialog.hpp"

namespace Utils
{

TextMenu::TextMenu(const std::string& title) : titleM(title), optionsM()
{
}

TextMenu::~TextMenu()
{
}

void TextMenu::show() const
{
   IO& io = IO::getInstance();
   io.writeString(titleM);
   std::uint8_t optionIndex = 1;
   for (std::string option : optionsM)
   {
      io.writeString(std::to_string(optionIndex++) + " - " + option);
   }
}

std::int64_t TextMenu::read() const
{
   return LimitedIntDialog("Choose option", optionsM.size()).read();
}

void TextMenu::addOption(const std::string& option)
{
   optionsM.push_back(option);
}

}
