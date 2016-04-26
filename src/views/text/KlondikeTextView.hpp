#ifndef VIEWS_TEXT_KLONDIKETEXTVIEW_HPP_
#define VIEWS_TEXT_KLONDIKETEXTVIEW_HPP_

#include "GameTextView.hpp"
#include "KlondikeView.hpp"
#include "StartTextView.hpp"
#include "ContinueTextView.hpp"
#include "SaveTextView.hpp"

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

   KlondikeView* clone();

   void visit(Controllers::StartController* startController);
   void visit(Controllers::GameController* gameController);
   void visit(Controllers::ContinueController* continueController);
   void visit(Controllers::SaveController* continueController);

private:
   StartTextView startViewM;
   GameTextView gameViewM;
   ContinueTextView continueViewM;
   SaveTextView saveViewM;
};

}

#endif
