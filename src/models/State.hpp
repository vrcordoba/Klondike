
#ifndef MODELS_STATE_HPP_
#define MODELS_STATE_HPP_

#include <cstdint>

namespace Models
{

enum class State : std::uint8_t
{
   INITIAL,
   GAME,
   UNDO_MOVE,
   REDO_MOVE,
   SAVE,
   LOAD,
   CONTINUE_GAME,
   END_GAME
};

}

#endif
