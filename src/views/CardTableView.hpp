#ifndef VIEWS_CARDTABLEVIEW_HPP_
#define VIEWS_CARDTABLEVIEW_HPP_

#include "CardTableController.hpp"
#include "CardView.hpp"

namespace Views
{

class CardTableView
{
public:
   explicit CardTableView(Controllers::CardTableController* cardTableController)
      : cardTableControllerM(cardTableController), cardViewM(nullptr) {};
   virtual ~CardTableView() {};

   virtual void show() = 0;

protected:
   Controllers::CardTableController* cardTableControllerM;
   CardView* cardViewM;
};

}

#endif
