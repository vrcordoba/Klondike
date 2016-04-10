#ifndef CONTROLLERS_MOVECONTROLLER_HPP_
#define CONTROLLERS_MOVECONTROLLER_HPP_

#include "OperationController.hpp"

namespace Controllers
{

class MoveController : public OperationController
{
public:
   virtual ~MoveController() {};
   virtual void move() = 0;
};

}

#endif
