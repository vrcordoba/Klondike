
#include "Klondike.hpp"
#include "LocalOperationController.hpp"

Klondike::Klondike()
   : logicM(), viewM()
{
}

Klondike::~Klondike()
{
}

void Klondike::play()
{
   Controllers::LocalOperationController* controller;
   do
   {
      controller = logicM.getController();
      if (nullptr != controller)
      {
         viewM.interact(controller);
      }
   } while(nullptr != controller);
}
