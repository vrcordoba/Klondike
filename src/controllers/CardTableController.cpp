
#include "CardTableController.hpp"

#include "Pile.hpp"
#include "Deck.hpp"
#include "CardTable.hpp"
#include "Score.hpp"

namespace Controllers
{

CardTableController::CardTableController(Models::Game& game)
   : Controller(game)
{
}

CardTableController::~CardTableController()
{
}

std::vector<FacadeCard> CardTableController::getDeck()
{
   return getFacadePile(Controller::getDeck());
}

std::vector<FacadeCard> CardTableController::getWaste()
{
   return getFacadePile(Controller::getWaste());
}

std::vector<FacadeCard> CardTableController::getTableau(std::uint8_t i)
{
   return getFacadePile(Controller::getTableau(i));
}

std::vector<FacadeCard> CardTableController::getFoundation(std::uint8_t i)
{
   return getFacadePile(Controller::getFoundation(i));
}

std::vector<FacadeCard> CardTableController::getFacadePile(const Models::Pile* pile)
{
   std::vector<FacadeCard> facadePile;
   for (auto card : pile->getCards())
   {
      FacadeCard facadeCard(card);
      facadePile.push_back(facadeCard);
   }
   return facadePile;
}

std::uint8_t CardTableController::getNumTableaus() const
{
   return Controller::getNumTableaus();
}

std::uint8_t CardTableController::getNumFoundations() const
{
   return Controller::getNumFoundations();
}

std::uint32_t CardTableController::getScore()
{
   const Models::Score& score = Controller::getScore();
   return score.getScore();
}

}
