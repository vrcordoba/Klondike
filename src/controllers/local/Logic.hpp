#ifndef CONTROLLERS_LOCAL_LOGIC_HPP_
#define CONTROLLERS_LOCAL_LOGIC_HPP_

#include "Game.hpp"
#include "DeckBuilder.hpp"

namespace Controllers
{

class OperationController;
class StartController;

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
   Models::DeckBuilder deckBuilderM;
   StartController* startControllerM;
};

}

#endif
