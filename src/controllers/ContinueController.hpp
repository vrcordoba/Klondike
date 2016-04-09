#ifndef CONTROLLERS_CONTINUECONTROLLER_HPP_
#define CONTROLLERS_CONTINUECONTROLLER_HPP_

#include "OperationController.hpp"

namespace Controllers
{

class ContinueController : public OperationController
{
public:
   virtual ~ContinueController() {};
   virtual void resume(bool otherGame) = 0;
};

}

#endif
