#ifndef CONTROLLERS_COMMANDS_SAVECOMMAND_HPP_
#define CONTROLLERS_COMMANDS_SAVECOMMAND_HPP_

#include "Command.hpp"

namespace Controllers
{

class SaveCommand: public Command
{
public:
   SaveCommand();
   ~SaveCommand();

   Command* clone();

   void execute();
};

}

#endif
