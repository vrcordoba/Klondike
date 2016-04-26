#ifndef VIEWS_VIEWPROTOTYPER_HPP_
#define VIEWS_VIEWPROTOTYPER_HPP_

#include <cstdint>
#include <map>
#include "ViewType.hpp"

namespace Views
{

class KlondikeView;

class ViewPrototyper final
{
public:
   ViewPrototyper();
   ~ViewPrototyper();

   ViewPrototyper(const ViewPrototyper&) = delete;
   ViewPrototyper& operator=(const ViewPrototyper&) = delete;

   KlondikeView* getView();

private:
   std::map<Configuration::ViewType, KlondikeView*> viewPrototypesM;
};

}

#endif
