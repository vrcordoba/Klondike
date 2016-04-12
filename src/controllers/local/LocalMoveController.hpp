#ifndef CONTROLLERS_LOCAL_LOCALMOVECONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALMOVECONTROLLER_HPP_

#include "MoveController.hpp"
#include "LocalController.hpp"
#include "LocalCardTableController.hpp"

namespace Controllers
{

class OperationControllerVisitor;
class CardTableController;

class LocalMoveController final : public MoveController, public LocalController
{
public:
   explicit LocalMoveController(Models::Game& game);
   ~LocalMoveController();

   LocalMoveController(const LocalMoveController&) = delete;
   LocalMoveController& operator=(const LocalMoveController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   void isValidMove() const;
   void move() const;

   CardTableController* getCardTableController();

private:
   LocalCardTableController cardTableControllerM;
};

}

#endif
