
#include "ContinueTextView.hpp"

#include "YesNoDialog.hpp"
#include "ContinueController.hpp"

namespace Views
{

ContinueTextView::ContinueTextView()
{
}

ContinueTextView::~ContinueTextView()
{
}

void ContinueTextView::interact(Controllers::ContinueController* continueController)
{
   Utils::YesNoDialog dialog("Do you want to play again?");
   continueController->ranking();
   continueController->resume(dialog.read());
}

}
