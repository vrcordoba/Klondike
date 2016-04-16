#ifndef CONTROLLERS_LOCAL_LOCALGAMECONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALGAMECONTROLLER_HPP_

#include "GameController.hpp"
#include "LocalController.hpp"
#include "LocalCardTableController.hpp"
#include "LocalMoveController.hpp"

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
   bool isGameWon() const;

   CardTableController* getCardTableController();

private:
   LocalMoveController localMoveControllerM;
   LocalCardTableController cardTableControllerM;
};

}

#endif
