#ifndef CONTROLLERS_DRAWCARDCOMMAND_HPP_
#define CONTROLLERS_DRAWCARDCOMMAND_HPP_

#include "CardCommand.hpp"

namespace Controllers
{

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

   void execute();
   void undo();

   void setController(Controller* controller);
};

}

#endif
