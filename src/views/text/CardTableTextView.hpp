#ifndef VIEWS_TEXT_CARDTABLETEXTVIEW_HPP_
#define VIEWS_TEXT_CARDTABLETEXTVIEW_HPP_

#include <vector>
#include "CardTableView.hpp"
#include "FacadeCard.hpp"

namespace Utils
{
class IO;
}

namespace Controllers
{
class CardTableController;
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
   void showDelimiter() const;
   void showDeck();
   void showWaste();
   void showFoundations();
   void showTableaus();
   void showPile(const std::vector<Controllers::FacadeCard>& pile);
   void showOnlyFirstCardInPile(const std::vector<Controllers::FacadeCard>& pile);
   void showScore();

   Utils::IO& ioM;
};

}

#endif
