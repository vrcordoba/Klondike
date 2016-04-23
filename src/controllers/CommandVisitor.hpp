#ifndef CONTROLLERS_COMMANDVISITOR_HPP_
#define CONTROLLERS_COMMANDVISITOR_HPP_

namespace Controllers
{

class MoveCommand;
class DrawCardCommand;
class LeaveCommand;
class ModifyHistoryCommand;

class CommandVisitor
{
public:
   virtual ~CommandVisitor() {};
   virtual bool visit(MoveCommand* moveCommand) = 0;
   virtual bool visit(DrawCardCommand* drawCardCommand) = 0;
   virtual bool visit(LeaveCommand* leaveCommand) = 0;
   virtual bool visit(ModifyHistoryCommand* modifyHistoryCommand) = 0;
};

}

#endif
