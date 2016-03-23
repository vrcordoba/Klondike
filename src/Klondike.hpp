#ifndef KLONDIKE_HPP_
#define KLONDIKE_HPP_

#include "Logic.hpp"
#include "KlondikeView.hpp"

class Klondike final
{
public:
   Klondike();
   ~Klondike();

   void play();

private:
   Controllers::Logic logicM;
   Views::KlondikeView viewM;
};

#endif
