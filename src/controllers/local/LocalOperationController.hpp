#ifndef CONTROLLERS_LOCALOPERATIONCONTROLLER_HPP_
#define CONTROLLERS_LOCALOPERATIONCONTROLLER_HPP_

#include "OperationController.hpp"

namespace Controllers
{

class OperationControllerVisitor;

class LocalOperationController :
   public Controllers::OperationController
{
protected:
   explicit LocalOperationController();
   virtual ~LocalOperationController();
public:
   virtual void accept(const OperationControllerVisitor&
      operationControllerVisitor) = 0;
};

}

#endif
