#ifndef CONTROLLERS_OPERATIONCONTROLLER_HPP_
#define CONTROLLERS_OPERATIONCONTROLLER_HPP_

class OperationControllerVisitor;

namespace Controllers
{

class OperationController
{
public:
   virtual ~OperationController() {};
   virtual void accept(const OperationControllerVisitor&
      operationControllerVisitor) = 0;
};

}

#endif
