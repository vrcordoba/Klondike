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

   bool accept(CommandVisitor* commandVisitor);
};

}

#endif
