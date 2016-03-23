
#include "Logic.hpp"
#include "KlondikeView.hpp"

class Klondike final
{
private:
   Logic logic;
   KlondikeView view;

public:
   Klondike();
   ~Klondike();

   void play();
};

