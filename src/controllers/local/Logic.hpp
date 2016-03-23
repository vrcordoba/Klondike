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

   LocalOperationController* getController() const;
};

}

#endif
