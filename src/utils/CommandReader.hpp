#ifndef UTILS_COMMANDREADER_HPP_
#define UTILS_COMMANDREADER_HPP_

#include <vector>
#include <string>

namespace Utils
{

class CommandReader final
{
public:
   CommandReader();
   ~CommandReader();

   std::vector<std::string> getCommand(const std::string& message) const;

private:
   std::vector<std::string> tokenizeCommand(const std::string& command) const;
};

}

#endif
