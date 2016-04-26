#ifndef CONTROLLERS_COMMANDS_DRAWCARDCOMMAND_HPP_
#define CONTROLLERS_COMMANDS_DRAWCARDCOMMAND_HPP_

#include "CardCommand.hpp"

namespace Controllers
{

class Command;
class CommandVisitor;
class Controller;

class DrawCardCommand final : public CardCommand
{
public:
   DrawCardCommand();
   ~DrawCardCommand();

   DrawCardCommand(const DrawCardCommand&) = delete;
   DrawCardCommand& operator=(const DrawCardCommand&) = delete;

   bool accept(CommandVisitor* commandVisitor);

   Command* clone();

   void execute();
   void undo();

   void setController(Controller* controller);

private:
   std::uint8_t numMovedCardsM;
};

}

#endif
