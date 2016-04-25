#ifndef VIEWS_TEXT_CARDTEXTVIEWPROTOTYPER_HPP_
#define VIEWS_TEXT_CARDTEXTVIEWPROTOTYPER_HPP_

#include <cstdint>
#include <map>
#include "CardView.hpp"
#include "DeckType.hpp"

namespace Views
{

class CardView;

class CardTextViewPrototyper final
{
public:
   CardTextViewPrototyper();
   ~CardTextViewPrototyper();

   CardView* getView() const;

private:
   std::map<Configuration::DeckType::Type, CardView*> cardViewPrototypesM;
};

}

#endif
