#ifndef UTILS_COMMANDREADER_HPP_
#define UTILS_COMMANDREADER_HPP_

#include <list>
#include <string>

namespace Utils
{

class CommandReader final
{
public:
   CommandReader();
   ~CommandReader();

   std::list<std::string> getCommand(const std::string& message) const;

private:
   std::list<std::string> tokenizeCommand(const std::string& command) const;
};

}

#endif
