#ifndef VIEWS_TEXT_KLONDIKETEXTVIEW_HPP_
#define VIEWS_TEXT_KLONDIKETEXTVIEW_HPP_

#include "KlondikeView.hpp"

namespace Controllers
{
   class OperationController;
}

namespace Views
{

class KlondikeTextView final : public KlondikeView
{
public:
   KlondikeTextView();
   ~KlondikeTextView();

   KlondikeTextView(const KlondikeTextView&) = delete;
   KlondikeTextView& operator=(const KlondikeTextView&) = delete;

   void interact(const Controllers::OperationController* operationController);
};

}

#endif
