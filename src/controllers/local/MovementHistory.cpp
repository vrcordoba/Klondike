
#include "MovementHistory.hpp"

namespace Controllers
{

MovementHistory::MovementHistory() : historyM()
{
}

MovementHistory::~MovementHistory()
{
   for (Command* command : historyM)
      delete command;
}

void MovementHistory::store(Command* command)
{
   historyM.push_back(command);
}

Command* MovementHistory::undo()
{
   Command* movement = historyM.back();
   historyM.pop_back();
   return movement;
}

}
