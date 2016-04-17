
#include "LocalCardTableController.hpp"

#include "Pile.hpp"
#include "Deck.hpp"
#include "CardTable.hpp"

namespace Controllers
{

LocalCardTableController::LocalCardTableController(Models::Game& game)
   : LocalController(game)
{
}

LocalCardTableController::~LocalCardTableController()
{
}

std::vector<FacadeCard> LocalCardTableController::getDeck()
{
   return getFacadePile(LocalController::getDeck());
}

std::vector<FacadeCard> LocalCardTableController::getWaste()
{
   return getFacadePile(LocalController::getWaste());
}

std::vector<FacadeCard> LocalCardTableController::getTableau(std::uint8_t i)
{
   return getFacadePile(LocalController::getTableau(i));
}

std::vector<FacadeCard> LocalCardTableController::getFoundation(std::uint8_t i)
{
   return getFacadePile(LocalController::getFoundation(i));
}

std::vector<FacadeCard> LocalCardTableController::getFacadePile(const Models::Pile* pile)
{
   std::vector<FacadeCard> facadePile;
   for (Models::Card card : pile->getCards())
   {
      FacadeCard facadeCard(card);
      facadePile.push_back(facadeCard);
   }
   return facadePile;
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
