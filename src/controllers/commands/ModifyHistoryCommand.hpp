#ifndef CONTROLLERS_COMMANDS_MODIFYHISTORYCOMMAND_HPP_
#define CONTROLLERS_COMMANDS_MODIFYHISTORYCOMMAND_HPP_

#include <cstdint>
#include "ValidationCommand.hpp"

namespace Controllers
{

class ModifyHistoryCommand final : public ValidationCommand
{
public:
   enum class Type : std::uint8_t
   {
      UNDO,
      REDO
   };

   explicit ModifyHistoryCommand(Type type);
   ~ModifyHistoryCommand();

   Command* clone();

   bool isValid();

   void execute();

private:
   Type typeM;
};

}

#endif
