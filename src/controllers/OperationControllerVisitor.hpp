#ifndef CONTROLLERS_OPERATIONCONTROLLERVISITOR_HPP_
#define CONTROLLERS_OPERATIONCONTROLLERVISITOR_HPP_

namespace Controllers
{

class StartController;

class OperationControllerVisitor
{
public:
   virtual ~OperationControllerVisitor() {};
   virtual void visit(StartController* startController) = 0;
};

}
#endif
