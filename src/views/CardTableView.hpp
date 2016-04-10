#ifndef VIEWS_CARDTABLEVIEW_HPP_
#define VIEWS_CARDTABLEVIEW_HPP_

namespace Controllers
{
   class CardTableController;
}

namespace Views
{

class CardTableView
{
public:
   virtual ~CardTableView() {};

   virtual void show() = 0;

private:
   Controllers::CardTableController& cardTableControllerM;
};

}

#endif
