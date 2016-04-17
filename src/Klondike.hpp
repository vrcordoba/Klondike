#ifndef KLONDIKE_HPP_
#define KLONDIKE_HPP_

#include "Logic.hpp"

class Klondike final
{
public:
   explicit Klondike();
   ~Klondike();

   void play();

private:
   Controllers::Logic logicM;
};

#endif
