
#include "ViewPrototyper.hpp"

#include <cassert>
#include <algorithm>
#include "KlondikeConfiguration.hpp"
#include "KlondikeTextView.hpp"

namespace Views
{

ViewPrototyper::ViewPrototyper()
{
   viewPrototypesM.emplace(Configuration::ViewType::TEXT, new KlondikeTextView());
}

ViewPrototyper::~ViewPrototyper()
{
   std::for_each(std::begin(viewPrototypesM), std::end(viewPrototypesM),
      [] (std::pair<const Configuration::ViewType, KlondikeView*>& pair)
      {
         delete pair.second;
      });
}

KlondikeView* ViewPrototyper::getView()
{
   std::map<Configuration::ViewType, KlondikeView*>::const_iterator viewIt =
      viewPrototypesM.find(Configuration::KlondikeConfiguration::getInstance().getViewType());
   assert(viewIt != viewPrototypesM.end());
   KlondikeView* view = viewIt->second->clone();
   return view;
}

}
