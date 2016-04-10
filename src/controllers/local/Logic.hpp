#ifndef CONTROLLERS_LOCAL_LOGIC_HPP_
#define CONTROLLERS_LOCAL_LOGIC_HPP_

#include "Game.hpp"

namespace Controllers
{

class OperationController;
class StartController;
class MoveController;
class ContinueController;

class Logic final
{
public:
   Logic();
   ~Logic();

   Logic(const Logic&) = delete;
   Logic& operator=(const Logic&) = delete;

   OperationController* getController() const;

private:
   Models::Game gameM;
   StartController* startControllerM;
   MoveController* moveControllerM;
   ContinueController* continueControllerM;
};

}

#endif
