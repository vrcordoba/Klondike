#ifndef CONTROLLERS_STARTCONTROLLER_HPP_
#define CONTROLLERS_STARTCONTROLLER_HPP_

#include <cstdint>
#include "Controller.hpp"
#include "OperationController.hpp"
#include "DeckType.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

class Logic;
class OperationControllerVisitor;

class StartController final : public Controller, public OperationController
{
public:
   StartController(Models::Game& game, Logic* logic);
   ~StartController();

   StartController(const StartController&) = delete;
   StartController& operator=(const StartController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   enum class GameType : std::uint8_t
   {
      NEW = 1,
      SAVED
   };

   void start(std::uint8_t numPlayers, GameType gameType,
      Configuration::DeckType::Type typeDeck);

private:
   void buildCardTable(std::uint8_t typeDeck);

   Logic* logicM;
};

}

#endif
