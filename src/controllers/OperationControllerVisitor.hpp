#ifndef CONTROLLERS_OPERATIONCONTROLLERVISITOR_HPP_
#define CONTROLLERS_OPERATIONCONTROLLERVISITOR_HPP_

namespace Controllers
{

class StartController;
class GameController;
class ContinueController;
class SaveController;
class LoadController;

class OperationControllerVisitor
{
public:
   virtual ~OperationControllerVisitor() {};
   virtual void visit(StartController* startController) = 0;
   virtual void visit(GameController* gameController) = 0;
   virtual void visit(ContinueController* continueController) = 0;
   virtual void visit(SaveController* continueController) = 0;
   virtual void visit(LoadController* loadController) = 0;
};

}
#endif
