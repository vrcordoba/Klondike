#ifndef CONTROLLERS_LOCAL_LOCALSTARTCONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALSTARTCONTROLLER_HPP_

#include <cstdint>
#include <vector>
#include <string>
#include "StartController.hpp"
#include "OperationController.hpp"

namespace Models
{
   class Game;
   class DeckBuilder;
}

namespace Controllers
{

class OperationControllerVisitor;

class LocalStartController final : public StartController
{
public:
   LocalStartController(Models::Game& game, Models::DeckBuilder& deckBuilder);
   ~LocalStartController();

   void accept(OperationControllerVisitor* operationControllerVisitor);

   std::vector<std::string> getDecks() const;
   void start(std::uint8_t numPlayers, std::uint8_t newOrSavedOption,
      std::uint8_t typeDeck) const;

private:
   Models::Game& gameM;
   Models::DeckBuilder& deckBuilderM;
};

}

#endif
