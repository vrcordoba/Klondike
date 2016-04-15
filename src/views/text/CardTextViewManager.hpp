#ifndef VIEWS_TEXT_CARDTEXTVIEWMANAGER_HPP_
#define VIEWS_TEXT_CARDTEXTVIEWMANAGER_HPP_

namespace Controllers
{
   class CardTableController;
}

namespace Views
{

class CardView;

class CardTextViewManager final
{
public:
   explicit CardTextViewManager(const Controllers::CardTableController* cardTableController);
   ~CardTextViewManager();

   CardView* getView() const;

private:
   const Controllers::CardTableController* cardTableControllerM;
};

}

#endif
