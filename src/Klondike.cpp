
#include "Klondike.hpp"
#include "LocalOperationController.hpp"

Klondike::Klondike()
   : logic(), view()
{
}

Klondike::~Klondike()
{
}

void Klondike::play()
{
   LocalOperationController* controller;
   do
   {
      controller = logic.getController();
      if (nullptr != controller)
      {
         view.interact(controller);
      }
   } while(nullptr != controller);
}
