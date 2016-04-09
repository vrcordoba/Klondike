#ifndef CONTROLLERS_LOCAL_LOCALSTARTCONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALSTARTCONTROLLER_HPP_

#include <cstdint>
#include <vector>
#include <string>
#include "StartController.hpp"

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

   void start(std::uint8_t numPlayers, std::uint8_t newOrSavedOption,
      std::uint8_t typeDeck) const;
   void accept(const OperationControllerVisitor& operationControllerVisitor);

   std::vector<std::string> getDecks() const;

private:
   Models::Game& gameM;
   Models::DeckBuilder& deckBuilderM;
};

}

#endif
