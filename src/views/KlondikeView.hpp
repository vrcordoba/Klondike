#ifndef VIEWS_KLONDIKEVIEW_HPP_
#define VIEWS_KLONDIKEVIEW_HPP_

namespace Controllers
{
   class OperationController;
}

namespace Views
{

class KlondikeView
{
public:
   virtual ~KlondikeView() {};
   virtual void interact(const Controllers::OperationController* operationController) = 0;
};

}

#endif
