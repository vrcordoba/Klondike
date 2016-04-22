#ifndef CONTROLLERS_MOVECONTROLLER_HPP_
#define CONTROLLERS_MOVECONTROLLER_HPP_

#include <cstdint>
#include <vector>
#include "Controller.hpp"
#include "MovementHistory.hpp"

namespace Models
{
class Game;
class Pile;
class Card;
}

namespace Controllers
{

class MoveCommand;
class DrawCardCommand;

class MoveController final : public Controller
{
public:
   explicit MoveController(Models::Game& game);
   ~MoveController();

   MoveController(const MoveController&) = delete;
   MoveController& operator=(const MoveController&) = delete;

   bool isValidMovement(const MoveCommand* command) const;
   void applyMovement(MoveCommand* command);
   void applyDrawCard(DrawCardCommand* command);

private:
   bool isValidOrigin(
      const MoveCommand* command) const;
   bool isIndexValid(
         std::uint8_t originPile, std::uint8_t originIndex) const;
   bool pileCompatibleWithNumberOfCards(
      std::uint8_t pile, std::uint8_t numCards) const;
   bool areEnoughCardsInPile(
      std::uint8_t pileId, std::uint8_t index, std::uint8_t numCards) const;
   bool isValidDestination(
      const MoveCommand* command) const;
   bool isCardStackableInDestination(
      const MoveCommand* command) const;
   Models::Card getCardToMove(
      const MoveCommand* command) const;
   Models::Pile* getPile(
      std::uint8_t pileId, std::uint8_t pileIndex) const;
   void moveCards(Models::Pile* originPile,
      Models::Pile* destinationPile, std::uint8_t numCards);

   MovementHistory movementHistoryM;
};

}

#endif
