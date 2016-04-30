#ifndef CONTROLLERS_COMMANDS_VALIDATIONCOMMAND_HPP_
#define CONTROLLERS_COMMANDS_VALIDATIONCOMMAND_HPP_

#include "Command.hpp"

namespace Controllers
{

class ValidationCommand : virtual public Command
{
public:
   virtual ~ValidationCommand();

   bool doesItHaveToBeValidated();
   virtual bool isValid() = 0;
};

}

#endif
