#ifndef CONTROLLERS_LOCALOPERATIONCONTROLLER_HPP_
#define CONTROLLERS_LOCALOPERATIONCONTROLLER_HPP_

#include "OperationController.hpp"

namespace Controllers
{

class OperationControllerVisitor;

class LocalOperationController :
   public OperationController
{
protected:
   LocalOperationController(/*const Game&*/);
   virtual ~LocalOperationController();
public:
   virtual void accept(const OperationControllerVisitor&
      operationControllerVisitor) = 0;
};

}

#endif
