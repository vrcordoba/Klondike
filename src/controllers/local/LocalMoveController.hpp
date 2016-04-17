#ifndef CONTROLLERS_LOCAL_LOCALMOVECONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALMOVECONTROLLER_HPP_

#include <cstdint>
#include <vector>
#include "LocalController.hpp"
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

class LocalMoveController final : public LocalController
{
public:
   explicit LocalMoveController(Models::Game& game);
   ~LocalMoveController();

   LocalMoveController(const LocalMoveController&) = delete;
   LocalMoveController& operator=(const LocalMoveController&) = delete;

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
