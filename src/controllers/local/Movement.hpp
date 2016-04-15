#ifndef CONTROLLERS_MOVEMENT_HPP_
#define CONTROLLERS_MOVEMENT_HPP_

namespace Controllers
{

class Pile;

class Movement final
{
public:
   Movement(Pile& origin, Pile& destination);
   ~Movement();

   void execute() const;

private:
   Pile& originM;
   Pile& destinationM;
};

}

#endif
