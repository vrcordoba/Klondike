#ifndef CONTROLLERS_LOCAL_DRAWCARDCOMMAND_HPP_
#define CONTROLLERS_LOCAL_DRAWCARDCOMMAND_HPP_

#include "Command.hpp"

namespace Controllers
{

class DrawCardCommand final : public Command
{
public:
   DrawCardCommand();
   ~DrawCardCommand();

   DrawCardCommand(const DrawCardCommand&) = delete;
   DrawCardCommand& operator=(const DrawCardCommand&) = delete;

   bool accept(CommandVisitor* commandVisitor);
};

}

#endif
