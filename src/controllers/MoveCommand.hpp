#ifndef CONTROLLERS_MOVECOMMAND_HPP_
#define CONTROLLERS_MOVECOMMAND_HPP_

#include <vector>
#include <cstdint>
#include "CardCommand.hpp"

namespace Models
{
class Card;
class Pile;
}

namespace Controllers
{

class CommandVisitor;
class Controller;

class MoveCommand final : public CardCommand
{
public:
   explicit MoveCommand(const std::vector<std::uint8_t>& additionalArguments);
   ~MoveCommand();

   MoveCommand(const MoveCommand&) = delete;
   MoveCommand& operator=(const MoveCommand&) = delete;

   bool accept(CommandVisitor* commandVisitor);

   void execute();
   void undo();

   void setController(Controller* controller);

   std::uint8_t getOriginPileType() const;
   std::uint8_t getOriginPileNumber() const;
   std::uint8_t getDestinationPileType() const;
   std::uint8_t getNumCards() const;

   bool isValidOrigin() const;
   bool isValidDestination() const;
   Models::Pile* getPile(std::uint8_t pileId, std::uint8_t pileIndex) const;

private:
   bool isIndexValid(std::uint8_t originPile, std::uint8_t originIndex) const;
   bool pileCompatibleWithNumberOfCards(std::uint8_t pile) const;
   bool areEnoughCardsInPile(std::uint8_t pileId, std::uint8_t index) const;
   bool isCardStackableInDestination() const;
   Models::Card getCardToMove() const;

   void updateScore(bool upturnScore, bool negativeScore = false);

   std::uint8_t originPileTypeM;
   std::uint8_t originPileNumberM;
   std::uint8_t destinationPileTypeM;
   std::uint8_t destinationPileNumberM;
   std::uint8_t numCardsM;
};

}

#endif
