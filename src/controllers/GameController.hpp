#ifndef CONTROLLERS_GAMECONTROLLER_HPP_
#define CONTROLLERS_GAMECONTROLLER_HPP_

#include "OperationController.hpp"

namespace Controllers
{

class CardTableController;
class Command;

class GameController : public OperationController
{
public:
   virtual ~GameController() {};

   virtual bool isValidCommand(Command* command) = 0;
   virtual void applyCommand(Command* command) = 0;
   virtual bool isGameWon() const = 0;
   virtual CardTableController* getCardTableController() = 0;
};

}

#endif
