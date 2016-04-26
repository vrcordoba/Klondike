
#include "Klondike.hpp"
#include "OperationController.hpp"
#include "KlondikeConfiguration.hpp"
#include "ViewPrototyper.hpp"
#include "KlondikeView.hpp"

Klondike::Klondike()
   : logicM()
{
   Configuration::KlondikeConfiguration::getInstance();
}

Klondike::~Klondike()
{
}

void Klondike::play()
{
   Views::ViewPrototyper viewManager;
   Views::KlondikeView* view = viewManager.getView();
   Controllers::OperationController* controller;
   do
   {
      controller = logicM.getController();
      if (nullptr != controller)
      {
         view->interact(controller);
      }
   } while(nullptr != controller);
}
