
#include "Klondike.hpp"

#include "OperationController.hpp"
#include "ViewPrototyper.hpp"
#include "KlondikeView.hpp"

Klondike::Klondike()
   : logicM()
{
}

Klondike::~Klondike()
{
}

void Klondike::play()
{
   Views::ViewPrototyper viewPrototyper;
   Views::KlondikeView* view = viewPrototyper.getView();
   Controllers::OperationController* controller;
   do
   {
      controller = logicM.getController();
      if (nullptr != controller)
      {
         view->interact(controller);
      }
   } while(nullptr != controller);
   delete view;
}
