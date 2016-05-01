#ifndef UTILS_NUMERICTEXTMENU_HPP_
#define UTILS_NUMERICTEXTMENU_HPP_

#include <string>
#include <list>
#include <cstdint>

namespace Utils
{

class NumericTextMenu final
{
public:
   explicit NumericTextMenu(const std::string& title);
   ~NumericTextMenu();

   void show() const;
   std::int64_t read() const;

   void addOption(const std::string& option);

private:
   std::string titleM;
   std::list<std::string> optionsM;
};

}

#endif
