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
   KlondikeView();
   ~KlondikeView();

   KlondikeView(const KlondikeView&) = delete;
   KlondikeView& operator=(const KlondikeView&) = delete;

   void interact(const Controllers::OperationController* operationController);
};

}

#endif
