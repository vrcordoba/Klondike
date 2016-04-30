#ifndef CONTROLLERS_COMMANDS_CARDCOMMANDVISITOR_HPP_
#define CONTROLLERS_COMMANDS_CARDCOMMANDVISITOR_HPP_

namespace Controllers
{

class DrawCardCommand;
class MoveCommand;

class CardCommandVisitor
{
public:
   virtual ~CardCommandVisitor() {};

   virtual void visit(DrawCardCommand* drawCardCommand) = 0;
   virtual void visit(MoveCommand* moveCommand) = 0;
};

}

#endif
