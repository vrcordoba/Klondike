#ifndef CONTROLLERS_GAMECONTROLLERVISITOR_HPP_
#define CONTROLLERS_GAMECONTROLLERVISITOR_HPP_

namespace Controllers
{

class ManualGameController;
class AutomaticGameController;

class GameControllerVisitor
{
public:
   virtual ~GameControllerVisitor() {};

   virtual void visit(ManualGameController* manualGameController) = 0;
   virtual void visit(AutomaticGameController* automaticGameController) = 0;
};

}

#endif
