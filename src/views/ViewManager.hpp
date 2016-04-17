#ifndef VIEWS_VIEWMANAGER_HPP_
#define VIEWS_VIEWMANAGER_HPP_

namespace Views
{

class KlondikeView;

class ViewManager final
{
public:
   ViewManager();
   ~ViewManager();

   ViewManager(const ViewManager&) = delete;
   ViewManager& operator=(const ViewManager&) = delete;

   KlondikeView* getView();

private:
   KlondikeView* viewM;
};

}

#endif
