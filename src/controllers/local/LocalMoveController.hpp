#ifndef CONTROLLERS_LOCAL_LOCALMOVECONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALMOVECONTROLLER_HPP_

#include <cstdint>
#include <vector>
#include "LocalController.hpp"
#include "Game.hpp"
#include "MovementHistory.hpp"

namespace Controllers
{

class LocalMoveController final : public LocalController
{
public:
   explicit LocalMoveController(Models::Game& game);
   ~LocalMoveController();

   LocalMoveController(const LocalMoveController&) = delete;
   LocalMoveController& operator=(const LocalMoveController&) = delete;

   bool isValidMovement(const Command& command) const;
   void applyMovement(const Command& command);
   void applyDrawCard(const Command& command);

private:
   bool isValidOrigin(
      const std::vector<std::uint8_t>& additionalArguments) const;
   bool isIndexValid(
         std::uint8_t originPile, std::uint8_t originIndex) const;
   bool pileCompatibleWithNumberOfCards(
      std::uint8_t pile, std::uint8_t numCards) const;
   bool areEnoughCardsInPile(
      std::uint8_t pileId, std::uint8_t index, std::uint8_t numCards) const;
   bool isValidDestination(
      const std::vector<std::uint8_t>& additionalArguments) const;
   bool isCardStackableInDestination(
      const std::vector<std::uint8_t>& additionalArguments) const;
   Models::Card getCardToMove(
      const std::vector<std::uint8_t>& additionalArguments) const;
   Models::Pile* getPile(
      std::uint8_t pileId, std::uint8_t pileIndex) const;
   void moveCards(Models::Pile* originPile,
      Models::Pile* destinationPile, std::uint8_t numCards);

   MovementHistory movementHistoryM;
};

}

#endif
