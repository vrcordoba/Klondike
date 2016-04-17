#ifndef CONTROLLERS_COMMANDTYPE_HPP_
#define CONTROLLERS_COMMANDTYPE_HPP_

#include <cstdint>

namespace Controllers
{

enum class CommandType
{
   ERROR,
   HELP,
   MOVE,
   DRAWCARD
};

}

#endif
