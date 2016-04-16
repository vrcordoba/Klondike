#ifndef CONTROLLERS_MOVEMENTHISTORY_HPP_
#define CONTROLLERS_MOVEMENTHISTORY_HPP_

#include <deque>
#include <cstdint>
#include "Command.hpp"

namespace Controllers
{

class MovementHistory final
{
public:
   MovementHistory();
   virtual ~MovementHistory();

   MovementHistory(const MovementHistory&) = delete;
   MovementHistory& operator=(const MovementHistory&) = delete;

   void store(const Command& movement);

   Command undo();

private:
   std::deque<Command> historyM;
};

}

#endif
