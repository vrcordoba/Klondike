
#include "MovementHistory.hpp"

namespace Controllers
{

MovementHistory::MovementHistory() : historyM()
{
}

MovementHistory::~MovementHistory()
{
}

void MovementHistory::store(const Command& movement)
{
   historyM.push_back(movement);
}

Command MovementHistory::undo()
{
   Command movement = historyM.back();
   historyM.pop_back();
   return movement;
}

}
