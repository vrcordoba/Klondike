#ifndef MODELS_MOVEMENT_HPP_
#define MODELS_MOVEMENT_HPP_

namespace Models
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
