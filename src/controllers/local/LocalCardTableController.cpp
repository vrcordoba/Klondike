
#include "LocalCardTableController.hpp"

#include "Pile.hpp"
#include "Deck.hpp"
#include "CardTable.hpp"

namespace Controllers
{

LocalCardTableController::LocalCardTableController(Models::Game& game)
   : LocalController(game), cardTableM(nullptr)
{
}

LocalCardTableController::~LocalCardTableController()
{
}

std::vector<FacadeCard> LocalCardTableController::getDeck()
{
   lazyInitCardTable();
   return getFacadePile(cardTableM->getDeck());
}

std::vector<FacadeCard> LocalCardTableController::getWaste()
{
   lazyInitCardTable();
   return getFacadePile(cardTableM->getWaste());
}

std::vector<FacadeCard> LocalCardTableController::getTableau(std::uint8_t i)
{
   lazyInitCardTable();
   return getFacadePile(cardTableM->getTableau(i));
}

std::vector<FacadeCard> LocalCardTableController::getFoundation(std::uint8_t i)
{
   lazyInitCardTable();
   return getFacadePile(cardTableM->getFoundation(i));
}

std::vector<FacadeCard> LocalCardTableController::getFacadePile(const Models::Pile& pile)
{
   std::vector<FacadeCard> facadePile;
   for (Models::Card card : pile.getCards())
   {
      FacadeCard facadeCard(card);
      facadePile.push_back(facadeCard);
   }
   return facadePile;
}

void LocalCardTableController::lazyInitCardTable()
{
   if (nullptr == cardTableM)
   {
      cardTableM = LocalController::getCardTable();
   }
}

std::uint8_t LocalCardTableController::getNumTableaus() const
{
   return LocalController::getNumTableaus();
}

std::uint8_t LocalCardTableController::getNumFoundations() const
{
   return LocalController::getNumFoundations();
}

}
