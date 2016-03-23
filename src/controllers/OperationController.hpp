
class OperationControllerVisitor;

class OperationController
{
public:
   virtual void accept(const OperationControllerVisitor&
      operationControllerVisitor) = 0;
};

