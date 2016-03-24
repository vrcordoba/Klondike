#ifndef CONTROLLERS_LOCAL_LOGIC_HPP_
#define CONTROLLERS_LOCAL_LOGIC_HPP_

namespace Controllers
{

class LocalOperationController;

class Logic final
{
public:
   Logic();
   ~Logic();

   Logic(const Logic&) = delete;
   Logic& operator=(const Logic&) = delete;

   LocalOperationController* getController() const;
};

}

#endif
