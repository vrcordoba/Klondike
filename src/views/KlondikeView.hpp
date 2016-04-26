#ifndef VIEWS_KLONDIKEVIEW_HPP_
#define VIEWS_KLONDIKEVIEW_HPP_

#include "OperationControllerVisitor.hpp"

namespace Controllers
{
class OperationController;
}

namespace Views
{

class KlondikeView : public Controllers::OperationControllerVisitor
{
public:
   virtual ~KlondikeView() {};
   virtual void interact(Controllers::OperationController* operationController) = 0;

   virtual KlondikeView* clone() = 0;
};

}

#endif
