#ifndef VIEWS_TEXT_CARDTEXTVIEWBUILDER_HPP_
#define VIEWS_TEXT_CARDTEXTVIEWBUILDER_HPP_

namespace Controllers
{
   class CardTableController;
}

namespace Views
{

class CardView;

class CardTextViewBuilder final
{
public:
   explicit CardTextViewBuilder(const Controllers::CardTableController* cardTableController);
   ~CardTextViewBuilder();

   CardView* build() const;

private:
   const Controllers::CardTableController* cardTableControllerM;
};

}

#endif
