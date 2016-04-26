#ifndef CONTROLLERS_COMMANDS_MODIFYHISTORYCOMMAND_HPP_
#define CONTROLLERS_COMMANDS_MODIFYHISTORYCOMMAND_HPP_

#include <cstdint>
#include "Command.hpp"

namespace Controllers
{

class CommandVisitor;

class ModifyHistoryCommand final : public Command
{
public:
   enum class Type : std::uint8_t
   {
      UNDO,
      REDO
   };

   explicit ModifyHistoryCommand(Type type);
   ~ModifyHistoryCommand();

   bool accept(CommandVisitor* commandVisitor);

   Command* clone();

   Type getType() const;

private:
   Type typeM;
};

}

#endif
