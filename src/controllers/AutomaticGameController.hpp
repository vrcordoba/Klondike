#ifndef CONTROLLERS_AUTOMATICGAMECONTROLLER_HPP_
#define CONTROLLERS_AUTOMATICGAMECONTROLLER_HPP_

#include <cstdint>
#include <vector>
#include "GameController.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

class GameControllerVisitor;
class Command;
class MoveCommand;
class DrawCardCommand;

class AutomaticGameController final : public GameController
{
public:
   explicit AutomaticGameController(Models::Game& game);
   ~AutomaticGameController();

   GameController* clone();

   void accept(GameControllerVisitor* gameControllerVisitor);

   Command* getValidCommand();

private:
   Command* getValidCommandTableauFoundation();
   Command* getValidCommandWasteFoundation();
   Command* getValidCommandTableauTableau();
   Command* getValidCommandWasteTableau();
   DrawCardCommand* getValidCommandDrawCard();
   MoveCommand* getValidMovementCommand(const std::vector<std::uint8_t>& additionalArguments);
   MoveCommand* getValidCommandTableauTableauNumCards(
      std::uint8_t originTableauId, std::uint8_t destinationTableauId);
   bool isMoveCommandInRecentCommandHistory(MoveCommand* moveCommand);

   std::uint16_t numMovementsM;
   const std::uint16_t MAX_MOVEMENTS = 500;
   const std::uint16_t NUM_MOVEMENTS_TO_CHECK_IN_HISTORY = 50;
};

}

#endif
