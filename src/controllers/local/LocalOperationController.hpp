
#include "OperationController.hpp"

class OperationControllerVisitor;

class LocalOperationController :
   public OperationController
{
protected:
   explicit LocalOperationController();
public:
   virtual void accept(const OperationControllerVisitor&
      operationControllerVisitor) = 0;
};

