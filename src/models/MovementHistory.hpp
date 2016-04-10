#ifndef MODELS_MOVEMENTHISTORY_HPP_
#define MODELS_MOVEMENTHISTORY_HPP_

#include <deque>
#include <cstdint>
#include "Movement.hpp"

namespace Models
{

class MovementHistory final
{
public:
   MovementHistory();
   virtual ~MovementHistory();

   MovementHistory(const MovementHistory&) = delete;
   MovementHistory& operator=(const MovementHistory&) = delete;

   void storeAndExecute(const Movement& movement);

   Movement undo();

private:
   std::deque<Movement> historyM;
};

}

#endif
