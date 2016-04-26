#ifndef CONTROLLERS_COMMANDS_MOVECOMMAND_HPP_
#define CONTROLLERS_COMMANDS_MOVECOMMAND_HPP_

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

class Command;
class CommandVisitor;
class Controller;

class MoveCommand final : public CardCommand
{
public:
   MoveCommand();
   ~MoveCommand();

   MoveCommand(const MoveCommand&) = delete;
   MoveCommand& operator=(const MoveCommand&) = delete;

   bool accept(CommandVisitor* commandVisitor);

   Command* clone();

   void execute();
   void undo();

   void setController(Controller* controller);
   void setAdditionalArguments(const std::vector<std::uint8_t>& additionalArguments);

   bool isValidOrigin() const;
   bool isValidDestination() const;

private:
   bool isIndexValid(std::uint8_t originPile, std::uint8_t originIndex) const;
   bool pileCompatibleWithNumberOfCards(std::uint8_t pile) const;
   bool areEnoughCardsInOriginPile() const;
   bool isCardStackableInDestination() const;

   Models::Card getCardToMove() const;
   Models::Pile* getPile(std::uint8_t pileId, std::uint8_t pileIndex) const;

   void updateScore(bool upturnScore, bool negativeScore = false);

   std::uint8_t originPileTypeM;
   std::uint8_t originPileNumberM;
   std::uint8_t destinationPileTypeM;
   std::uint8_t destinationPileNumberM;
   std::uint8_t numCardsM;

   bool previousCardInPileNotUpturnedM;
};

}

#endif
