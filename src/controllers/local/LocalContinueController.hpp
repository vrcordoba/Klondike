#ifndef CONTROLLERS_LOCAL_LOCALCONTINUECONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALCONTINUECONTROLLER_HPP_

#include "ContinueController.hpp"
#include "OperationController.hpp"

namespace Controllers
{

class OperationControllerVisitor;

class LocalContinueController: public ContinueController
{
public:
   LocalContinueController();
   ~LocalContinueController();

   void accept(OperationControllerVisitor* operationControllerVisitor);

   void resume(bool otherGame);
};

}

#endif
