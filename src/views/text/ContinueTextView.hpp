#ifndef VIEWS_TEXT_CONTINUETEXTVIEW_HPP_
#define VIEWS_TEXT_CONTINUETEXTVIEW_HPP_

#include "ContinueView.hpp"

namespace Controllers
{
class ContinueController;
}

namespace Views
{

class ContinueTextView : public ContinueView
{
public:
   ContinueTextView();
   virtual ~ContinueTextView();

   ContinueTextView(const ContinueTextView&) = delete;
   ContinueTextView& operator=(const ContinueTextView&) = delete;

   void interact(Controllers::ContinueController* continueController);
};

}

#endif
