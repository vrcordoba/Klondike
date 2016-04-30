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

class CardCommandVisitor;

class CardCommand : virtual public Command
{
public:
   CardCommand();
   virtual ~CardCommand();

   virtual void accept(CardCommandVisitor* cardCommandVisitor) = 0;

   virtual void undo() = 0;
   bool isUndoable();

   virtual void moveCards(Models::Pile* originPile, Models::Pile* destinationPile,
      std::uint8_t numCards);
};

}

#endif
