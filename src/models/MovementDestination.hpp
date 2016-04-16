#ifndef MODELS_MOVEMENTDESTINATION_HPP_
#define MODELS_MOVEMENTDESTINATION_HPP_

namespace Models
{

class Card;

class MovementDestination
{
public:
   virtual ~MovementDestination() {};
   virtual bool isValidDestination(const Card& card) const = 0;
};

}

#endif
