#ifndef VIEWS_TEXT_MOVETEXTVIEW_HPP_
#define VIEWS_TEXT_MOVETEXTVIEW_HPP_

#include "MoveView.hpp"
#include "TextMenu.hpp"

namespace Controllers
{
   class MoveController;
}

namespace Views
{

class MoveTextView final : public MoveView
{
public:
   MoveTextView();
   ~MoveTextView();

   MoveTextView(const MoveTextView&) = delete;
   MoveTextView& operator=(const MoveTextView&) = delete;

   void interact(Controllers::MoveController* moveController);
};

}

#endif
