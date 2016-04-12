#ifndef VIEWS_TEXT_CARDTABLETEXTVIEW_HPP_
#define VIEWS_TEXT_CARDTABLETEXTVIEW_HPP_

#include "IO.hpp"
#include "CardTableView.hpp"

namespace Controllers
{
   class CardTableController;
}

namespace Models
{
   class Pile;
}

namespace Views
{

class CardView;

class CardTableTextView final : public CardTableView
{
public:
   explicit CardTableTextView(Controllers::CardTableController* cardTableController);
   ~CardTableTextView();

   CardTableTextView(const CardTableTextView&) = delete;
   CardTableTextView& operator=(const CardTableTextView&) = delete;

   void show();

private:
   void buildCardView();
   void showDelimiter();
   void showDeck();
   void showWaste();
   void showFoundations();
   void showTableaus();
   std::string showPile(const Models::Pile& pile);

   Utils::IO ioM;
};

}

#endif
