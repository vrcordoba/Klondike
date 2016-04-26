#ifndef CONTROLLERS_COMMANDS_SAVECOMMAND_HPP_
#define CONTROLLERS_COMMANDS_SAVECOMMAND_HPP_

#include "Command.hpp"

namespace Controllers
{

class CommandVisitor;

class SaveCommand: public Command
{
public:
   SaveCommand();
   ~SaveCommand();

   bool accept(CommandVisitor* commandVisitor);

   Command* clone();
};

}

#endif
