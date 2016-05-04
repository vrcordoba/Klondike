
#include "CardCommandDiscriminator.hpp"

#include "CardCommand.hpp"

namespace Controllers
{

CardCommandDiscriminator::CardCommandDiscriminator(CardCommand* cardCommand) :
   cardCommandM(cardCommand), typeM(Type::MOVE)
{
}

CardCommandDiscriminator::~CardCommandDiscriminator()
{
}

void CardCommandDiscriminator::visit(DrawCardCommand* drawCardCommand)
{
   typeM = Type::DRAW;
}

void CardCommandDiscriminator::visit(MoveCommand* moveCommand)
{
   typeM = Type::MOVE;
}

bool CardCommandDiscriminator::isSameType(CardCommand& cardCommand)
{
   cardCommandM->accept(this);
   Type type1 = typeM;
   cardCommand.accept(this);
   Type type2 = typeM;
   return type1 == type2;
}

}
