#ifndef CONTROLLERS_COMMANDS_COMMANDTYPE_HPP_
#define CONTROLLERS_COMMANDS_COMMANDTYPE_HPP_

#include <cstdint>

namespace Controllers
{

enum class CommandType :std::uint8_t
{
   ERROR,
   HELP,
   MOVE,
   DRAWCARD,
   INIT,
   LEAVE,
   UNDO,
   REDO,
   SAVE
};

}

#endif
