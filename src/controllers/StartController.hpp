#ifndef CONTROLLERS_STARTCONTROLLER_HPP_
#define CONTROLLERS_STARTCONTROLLER_HPP_

#include <cstdint>
#include <list>
#include <string>
#include "Controller.hpp"
#include "OperationController.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

class OperationControllerVisitor;

class StartController final : public Controller, public OperationController
{
public:
   explicit StartController(Models::Game& game);
   ~StartController();

   StartController(const StartController&) = delete;
   StartController& operator=(const StartController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   void start(std::uint8_t numPlayers, std::uint8_t newOrSavedOption,
      std::uint8_t typeDeck);

private:
   void buildCardTable(std::uint8_t typeDeck);
};

}

#endif
