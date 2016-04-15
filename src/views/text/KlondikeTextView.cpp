
#include "KlondikeTextView.hpp"

#include <cassert>
#include "OperationController.hpp"

namespace Views
{

KlondikeTextView::KlondikeTextView()
{
}

KlondikeTextView::~KlondikeTextView()
{
}

void KlondikeTextView::interact(Controllers::OperationController*
   operationController)
{
   assert(nullptr != operationController);
   operationController->accept(this);
}

void KlondikeTextView::visit(Controllers::StartController* startController)
{
   startViewM.interact(startController);
}

void KlondikeTextView::visit(Controllers::GameController* gameController)
{
   gameViewM.interact(gameController);
}

void KlondikeTextView::visit(Controllers::ContinueController* continueController)
{
   continueViewM.interact(continueController);
}

}
