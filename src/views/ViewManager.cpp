
#include "ViewManager.hpp"

#include <cassert>
#include "KlondikeConfiguration.hpp"
#include "KlondikeTextView.hpp"

namespace Views
{

ViewManager::ViewManager() : viewM(nullptr)
{
}

ViewManager::~ViewManager()
{
   delete viewM;
}

KlondikeView* ViewManager::getView()
{
   Configuration::ViewType viewType = Configuration::KlondikeConfiguration::getInstance().getViewType();
   if (Configuration::ViewType::TEXT == viewType)
   {
      viewM = new KlondikeTextView();
   }
   return viewM;
}

}
