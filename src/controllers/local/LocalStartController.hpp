#ifndef CONTROLLERS_LOCAL_LOCALSTARTCONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALSTARTCONTROLLER_HPP_

#include <cstdint>
#include <list>
#include <string>
#include "StartController.hpp"
#include "LocalController.hpp"

namespace Models
{
class Game;
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

   void start(std::uint8_t numPlayers, std::uint8_t newOrSavedOption,
      std::uint8_t typeDeck);

private:
   void buildCardTable(std::uint8_t typeDeck);
};

}

#endif
