#ifndef CONTROLLERS_LOCAL_LOCALCARDTABLECONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALCARDTABLECONTROLLER_HPP_

#include <vector>
#include "CardTableController.hpp"
#include "LocalController.hpp"

namespace Models
{
   class Pile;
   class Deck;
   class CardTable;
}

namespace Controllers
{

class LocalCardTableController final : public CardTableController,
   public LocalController
{
public:
   LocalCardTableController(Models::Game& game);
   ~LocalCardTableController();

   LocalCardTableController(const LocalCardTableController&) = delete;
   LocalCardTableController& operator=(const LocalCardTableController&) = delete;

   Models::DeckType::Name getDeckType() const;

   Models::Deck& getDeck();
   Models::Pile& getWaste();
   std::vector<Models::Pile> getTableaus();
   std::vector<Models::Pile> getFoundations();

private:

   void lazyInitCardTable();

   Models::CardTable* cardTableM;
};

}

#endif
