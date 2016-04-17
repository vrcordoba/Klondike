
#include "Klondike.hpp"
#include "OperationController.hpp"
#include "KlondikeConfiguration.hpp"
#include "ViewManager.hpp"
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
   Views::ViewManager viewManager;
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
