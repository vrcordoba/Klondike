#ifndef UTILS_TEXTMENU_HPP_
#define UTILS_TEXTMENU_HPP_

#include <string>
#include <list>
#include <cstdint>

namespace Utils
{

class TextMenu final
{
public:
   TextMenu(const std::string& title);
   ~TextMenu();

   TextMenu(const TextMenu&) = delete;
   TextMenu& operator=(const TextMenu&) = delete;

   void show() const;
   std::int64_t read() const;

   void addOption(const std::string& option);
   void setAdditionalInformation(const std::string& additionalInformation);

private:
   const std::string titleM;
   std::list<std::string> optionsM;
   std::string additionalInformationM;
};

}

#endif
