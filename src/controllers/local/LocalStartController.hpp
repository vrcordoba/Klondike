#ifndef CONTROLLERS_LOCAL_LOCALSTARTCONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALSTARTCONTROLLER_HPP_

#include <cstdint>
#include <vector>
#include <string>
#include "StartController.hpp"
#include "LocalController.hpp"
#include "DeckManager.hpp"

namespace Models
{
   class Game;
   class CardTable;
}

namespace Controllers
{

class OperationControllerVisitor;

class LocalStartController final : public StartController, public LocalController
{
public:
   explicit LocalStartController(Models::Game& game);
   ~LocalStartController();

   LocalStartController(const LocalStartController&) = delete;
   LocalStartController& operator=(const LocalStartController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   std::vector<std::string> getDeckDescriptions() const;
   void start(std::uint8_t numPlayers, std::uint8_t newOrSavedOption,
      std::uint8_t typeDeck);

private:
   void buildCardTable(std::uint8_t typeDeck);

   Models::DeckManager deckManagerM;
   Models::CardTable* cardTableM;
};

}

#endif
