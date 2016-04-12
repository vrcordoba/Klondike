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
   explicit TextMenu(const std::string& title);
   ~TextMenu();

   void show() const;
   std::int64_t read() const;

   void addOption(const std::string& option);

private:
   std::string titleM;
   std::list<std::string> optionsM;
};

}

#endif
