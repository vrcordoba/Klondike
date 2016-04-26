#ifndef CONTROLLERS_COMMANDS_COMMAND_HPP_
#define CONTROLLERS_COMMANDS_COMMAND_HPP_

namespace Controllers
{

class CommandVisitor;

class Command
{
public:
   virtual ~Command() {};
   virtual bool accept(CommandVisitor* commandVisitor) = 0;

   virtual Command* clone() = 0;
};

}

#endif
