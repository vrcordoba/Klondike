#ifndef VIEWS_KLONDIKEVIEW_HPP_
#define VIEWS_KLONDIKEVIEW_HPP_

namespace Controllers
{
   class OperationController;
}

namespace Views
{

class KlondikeView final
{
public:
   explicit KlondikeView();
   ~KlondikeView();

   void interact(const Controllers::OperationController* operationController);
};

}

#endif
