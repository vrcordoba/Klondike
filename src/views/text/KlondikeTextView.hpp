#ifndef VIEWS_TEXT_KLONDIKETEXTVIEW_HPP_
#define VIEWS_TEXT_KLONDIKETEXTVIEW_HPP_

#include "KlondikeView.hpp"
#include "StartTextView.hpp"
#include "MoveTextView.hpp"
#include "ContinueTextView.hpp"

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

   void interact(Controllers::OperationController* operationController);

   void visit(Controllers::StartController* startController);
   void visit(Controllers::MoveController* moveController);
   void visit(Controllers::ContinueController* continueController);

private:
   StartTextView startViewM;
   MoveTextView moveViewM;
   ContinueTextView continueViewM;
};

}

#endif
