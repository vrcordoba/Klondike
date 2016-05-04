#ifndef CONTROLLERS_COMMANDS_CARDCOMMANDDISCRIMINATOR_HPP_
#define CONTROLLERS_COMMANDS_CARDCOMMANDDISCRIMINATOR_HPP_

#include <cstdint>
#include "CardCommandVisitor.hpp"

namespace Controllers
{

class CardCommand;
class DrawCardCommand;
class MoveCommand;

class CardCommandDiscriminator final : public CardCommandVisitor
{
public:
   explicit CardCommandDiscriminator(CardCommand* cardCommand);
   ~CardCommandDiscriminator();

   void visit(DrawCardCommand* drawCardCommand);
   void visit(MoveCommand* moveCommand);

   bool isSameType(CardCommand& cardCommand);

private:
   enum class Type : std::uint8_t
   {
      MOVE,
      DRAW
   };

   CardCommand* cardCommandM;
   Type typeM;
};

}

#endif
