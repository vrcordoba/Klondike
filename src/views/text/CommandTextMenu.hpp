#ifndef VIEWS_COMMANDTEXTMENU_HPP_
#define VIEWS_COMMANDTEXTMENU_HPP_

#include <cstdint>
#include <vector>
#include <string>
#include "CommandType.hpp"
#include "IO.hpp"
#include "CommandInterpreter.hpp"

namespace Views
{

class CommandTextMenu final
{
public:
   explicit CommandTextMenu(const std::string& title);
   ~CommandTextMenu();

   Controllers::CommandType getCommand();
   std::vector<std::uint8_t> getAdditionalArguments() const;

   void addCommand(const std::string& commandId, const std::string& commandHelp,
      Controllers::CommandType commandType);

   void showWrongCommand() const;

private:
   std::vector<std::string> tokenizeCommand(const std::string& command) const;

   bool errorOrHelpInCommand() const;
   bool analyzeArguments();
   void showWrongNumberOfParameters() const;
   void showHelp() const;

   std::string titleM;
   Utils::IO& ioM;
   CommandInterpreter commandInterpreterM;
};

}

#endif
