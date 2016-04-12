#ifndef CONTROLLERS_MOVECONTROLLER_HPP_
#define CONTROLLERS_MOVECONTROLLER_HPP_

#include "OperationController.hpp"

namespace Controllers
{

class CardTableController;

class MoveController : public OperationController
{
public:
   virtual ~MoveController() {};

   virtual void isValidMove() const = 0;
   virtual void move() const = 0;
   virtual CardTableController* getCardTableController() = 0;

   enum class CommandType
   {
      ERROR,
      HELP,
      MOVE,
      DRAWCARD
   };
};

}

#endif
