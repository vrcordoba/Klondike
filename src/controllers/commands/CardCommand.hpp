#ifndef CONTROLLERS_COMMANDS_CARDCOMMAND_HPP_
#define CONTROLLERS_COMMANDS_CARDCOMMAND_HPP_

#include <cstdint>
#include "Command.hpp"

namespace Models
{
class Pile;
}

namespace Controllers
{

class Controller;
class CardCommandVisitor;

class CardCommand : public Command
{
public:
   CardCommand();
   virtual ~CardCommand();

   virtual void execute() = 0;
   virtual void undo() = 0;

   virtual void setController(Controller* controller);
   virtual Controller* getController() const;

   virtual void moveCards(Models::Pile* originPile, Models::Pile* destinationPile,
      std::uint8_t numCards);

private:
   Controller* controllerM;
};

}

#endif
