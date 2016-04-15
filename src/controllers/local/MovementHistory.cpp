
#include "MovementHistory.hpp"

namespace Controllers
{

MovementHistory::MovementHistory() : historyM()
{
}

MovementHistory::~MovementHistory()
{
}

void MovementHistory::storeAndExecute(const Movement& movement)
{
   historyM.push_back(movement);
   movement.execute();
}

Movement MovementHistory::undo()
{
   Movement movement = historyM.back();
   historyM.pop_back();
   return movement;
}

}
