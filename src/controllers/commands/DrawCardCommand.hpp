#ifndef CONTROLLERS_COMMANDS_DRAWCARDCOMMAND_HPP_
#define CONTROLLERS_COMMANDS_DRAWCARDCOMMAND_HPP_

#include <cstdint>
#include "CardCommand.hpp"

namespace Controllers
{

class Command;
class CardCommandVisitor;

class DrawCardCommand final : public CardCommand
{
public:
   DrawCardCommand();
   ~DrawCardCommand();

   DrawCardCommand(const DrawCardCommand& otherDrawCardCommand);

   void accept(CardCommandVisitor* cardCommandVisitor);

   Command* clone();

   void execute();
   void undo();

private:
   std::uint8_t numMovedCardsM;
};

}

#endif
