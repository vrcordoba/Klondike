#ifndef CONTROLLERS_LOCAL_LOCALCARDTABLECONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALCARDTABLECONTROLLER_HPP_

#include <cstdint>
#include <vector>
#include "CardTableController.hpp"
#include "LocalController.hpp"

namespace Models
{
   class Pile;
   class CardTable;
}

namespace Controllers
{

class LocalCardTableController final : public CardTableController,
   public LocalController
{
public:
   explicit LocalCardTableController(Models::Game& game);
   ~LocalCardTableController();

   LocalCardTableController(const LocalCardTableController&) = delete;
   LocalCardTableController& operator=(const LocalCardTableController&) = delete;

   Models::DeckType::Name getDeckType() const;

   std::vector<FacadeCard> getDeck();
   std::vector<FacadeCard> getWaste();
   std::vector<FacadeCard> getTableau(std::uint8_t i);
   std::vector<FacadeCard> getFoundation(std::uint8_t i);
   std::uint8_t getNumTableaus() const;
   std::uint8_t getNumFoundations() const;

private:

   std::vector<FacadeCard> getFacadePile(const Models::Pile& pile);
   void lazyInitCardTable();

   Models::CardTable* cardTableM;
};

}

#endif
