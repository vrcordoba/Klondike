#ifndef VIEWS_TEXT_CARDTEXTVIEWMANAGER_HPP_
#define VIEWS_TEXT_CARDTEXTVIEWMANAGER_HPP_

namespace Views
{

class CardView;

class CardTextViewManager final
{
public:
   CardTextViewManager();
   ~CardTextViewManager();

   CardView* getView() const;
};

}

#endif
