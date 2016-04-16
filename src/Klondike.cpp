
#include "Klondike.hpp"
#include "OperationController.hpp"
#include "KlondikeConfiguration.hpp"

Klondike::Klondike(Views::KlondikeView& view)
   : logicM(), viewM(view)
{
   Configuration::KlondikeConfiguration::getInstance();
}

Klondike::~Klondike()
{
}

void Klondike::play()
{
   Controllers::OperationController* controller;
   do
   {
      controller = logicM.getController();
      if (nullptr != controller)
      {
         viewM.interact(controller);
      }
   } while(nullptr != controller);
}
