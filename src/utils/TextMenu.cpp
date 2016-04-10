
#include "TextMenu.hpp"

#include "IO.hpp"
#include "LimitedIntDialog.hpp"

namespace Utils
{

TextMenu::TextMenu(const std::string& title) : titleM(title), optionsM(),
   additionalInformationM()
{
}

TextMenu::~TextMenu()
{
}

void TextMenu::show() const
{
   IO io;
   io.writeString(titleM);
   if (not additionalInformationM.empty())
   {
      io.writeString(additionalInformationM);
   }
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

void TextMenu::setAdditionalInformation(const std::string& additionalInformation)
{
   additionalInformationM = additionalInformation;
}

}
