#ifndef KLONDIKE_HPP_
#define KLONDIKE_HPP_

#include "Logic.hpp"
#include "KlondikeView.hpp"

class Klondike final
{
public:
   explicit Klondike(Views::KlondikeView& view);
   ~Klondike();

   void play();

private:
   Controllers::Logic logicM;
   Views::KlondikeView& viewM;
};

#endif
