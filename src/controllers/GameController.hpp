#ifndef CONTROLLERS_GAMECONTROLLER_HPP_
#define CONTROLLERS_GAMECONTROLLER_HPP_

#include <cstdint>
#include "OperationController.hpp"

namespace Controllers
{

class CardTableController;

class GameController : public OperationController
{
public:
   virtual ~GameController() {};

   virtual void isValidMove() const = 0;
   virtual void move() const = 0;
   virtual CardTableController* getCardTableController() = 0;

   enum class CommandType :std::uint8_t
   {
      ERROR,
      HELP,
      MOVE,
      DRAWCARD
   };
};

}

#endif
