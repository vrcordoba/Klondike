
#include "MoveCommand.hpp"

#include "CommandVisitor.hpp"

namespace Controllers
{

MoveCommand::MoveCommand(const std::vector<std::uint8_t>& additionalArguments) :
   originPileTypeM(additionalArguments[0]), originPileNumberM(additionalArguments[1]),
   destinationPileTypeM(additionalArguments[2]), destinationPileNumberM(additionalArguments[3]),
   numCardsM(additionalArguments[4])
{
}

MoveCommand::~MoveCommand()
{
}

bool MoveCommand::accept(CommandVisitor* commandVisitor)
{
   return commandVisitor->visit(this);
}

std::uint8_t MoveCommand::getOriginPileType() const
{
   return originPileTypeM;
}

std::uint8_t MoveCommand::getOriginPileNumber() const
{
   return originPileNumberM;
}

std::uint8_t MoveCommand::getDestinationPileType() const
{
   return destinationPileTypeM;
}

std::uint8_t MoveCommand::getDestinationPileNumber() const
{
   return destinationPileNumberM;
}

std::uint8_t MoveCommand::getNumCards() const
{
   return numCardsM;
}

}
