#ifndef CONTROLLERS_LOGIC_HPP_
#define CONTROLLERS_LOGIC_HPP_

#include "Game.hpp"
#include "OperationController.hpp"

namespace Controllers
{

class Logic final
{
public:
   Logic();
   ~Logic();

   Logic(const Logic&) = delete;
   Logic& operator=(const Logic&) = delete;

   OperationController* getController() const;

private:
   Models::Game gameM;
   std::map<Models::State, OperationController*> controllersM;
};

}

#endif
