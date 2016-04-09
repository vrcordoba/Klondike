#ifndef CONTROLLERS_OPERATIONCONTROLLER_HPP_
#define CONTROLLERS_OPERATIONCONTROLLER_HPP_

#include "OperationControllerVisitor.hpp"

namespace Controllers
{

class OperationController
{
public:
   virtual ~OperationController() {};
   virtual void accept(OperationControllerVisitor* operationControllerVisitor) = 0;
};

}

#endif
