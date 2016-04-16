#ifndef CONTROLLERS_LOCAL_LOCALGAMECONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALGAMECONTROLLER_HPP_

#include "GameController.hpp"
#include "LocalController.hpp"
#include "LocalCardTableController.hpp"

namespace Controllers
{

class OperationControllerVisitor;
class CardTableController;
class Command;

class LocalGameController final : public GameController, public LocalController
{
public:
   explicit LocalGameController(Models::Game& game);
   ~LocalGameController();

   LocalGameController(const LocalGameController&) = delete;
   LocalGameController& operator=(const LocalGameController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   bool isValidCommand(const Command& command) const;
   void applyCommand(const Command& command);

   CardTableController* getCardTableController();

private:
   bool isValidMovement(const Command& command) const;
   bool isValidOrigin(
      std::uint8_t originPile, std::uint8_t originIndex) const;
   bool isValidDestination(
      const std::vector<std::uint8_t>& additionalArguments) const;
   bool isIndexValid(
      std::uint8_t originPile, std::uint8_t originIndex) const;
   bool isCardStackableInDestination(
      const std::vector<std::uint8_t>& additionalArguments) const;
   Models::Card getCardToMove(
      const std::vector<std::uint8_t>& additionalArguments) const;
   Models::Pile* getPile(
      std::uint8_t pileId, std::uint8_t pileIndex) const;
   void applyMovement(const Command& command);

   LocalCardTableController cardTableControllerM;
};

}

#endif
