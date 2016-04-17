
#ifndef MODELS_STATE_HPP_
#define MODELS_STATE_HPP_

#include <cstdint>

namespace Models
{

enum class State : std::uint8_t
{
   INITIAL,
   GAME,
   UNDO,
   REDO,
   SAVE,
   LOAD,
   CONTINUE,
   END
};

}

#endif
