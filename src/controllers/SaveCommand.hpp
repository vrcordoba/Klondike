#ifndef CONTROLLERS_SAVECOMMAND_HPP_
#define CONTROLLERS_SAVECOMMAND_HPP_

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
};

}

#endif
