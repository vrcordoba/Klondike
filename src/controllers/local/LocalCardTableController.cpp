
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

Models::DeckType::Name LocalCardTableController::getDeckType() const
{
   return LocalController::getDeckType();
}

LocalCardTableController::~LocalCardTableController()
{
}

Models::Deck& LocalCardTableController::getDeck()
{
   if (nullptr == cardTableM)
   {
      lazyInitCardTablePtr();
   }
   return cardTableM->getDeck();
}

Models::Pile& LocalCardTableController::getWaste()
{
   if (nullptr == cardTableM)
   {
      lazyInitCardTablePtr();
   }
   return cardTableM->getWaste();
}

std::vector<Models::Pile> LocalCardTableController::getTableaus()
{
   if (nullptr == cardTableM)
   {
      lazyInitCardTablePtr();
   }
   std::vector<Models::Pile> tableaus;
   for (std::uint8_t i = 0; i < LocalController::getNumTableaus(); ++i)
   {
      tableaus.push_back(cardTableM->getTableau(i));
   }
   return tableaus;
}

std::vector<Models::Pile> LocalCardTableController::getFoundations()
{
   if (nullptr == cardTableM)
   {
      lazyInitCardTablePtr();
   }
   std::vector<Models::Pile> foundations;
   for (std::uint8_t i = 0; i < cardTableM->getNumSuits(); ++i)
   {
      foundations.push_back(cardTableM->getFoundation(i));
   }
   return foundations;
}

void LocalCardTableController::lazyInitCardTablePtr()
{
   cardTableM = LocalController::getCardTable();
}

}
