#ifndef CONTROLLERS_LOCAL_MOVECOMMAND_HPP_
#define CONTROLLERS_LOCAL_MOVECOMMAND_HPP_

#include <vector>
#include <cstdint>
#include "Command.hpp"

namespace Controllers
{

class MoveCommand final : public Command
{
public:
   explicit MoveCommand(const std::vector<std::uint8_t>& additionalArguments);
   ~MoveCommand();

   MoveCommand(const MoveCommand&) = delete;
   MoveCommand& operator=(const MoveCommand&) = delete;

   bool accept(CommandVisitor* commandVisitor);

   std::uint8_t getOriginPileType() const;
   std::uint8_t getOriginPileNumber() const;
   std::uint8_t getDestinationPileType() const;
   std::uint8_t getDestinationPileNumber() const;
   std::uint8_t getNumCards() const;

private:
   std::uint8_t originPileTypeM;
   std::uint8_t originPileNumberM;
   std::uint8_t destinationPileTypeM;
   std::uint8_t destinationPileNumberM;
   std::uint8_t numCardsM;
};

}

#endif
