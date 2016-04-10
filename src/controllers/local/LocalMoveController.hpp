#ifndef CONTROLLERS_LOCAL_LOCALMOVECONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALMOVECONTROLLER_HPP_

#include "MoveController.hpp"
#include "LocalController.hpp"

namespace Controllers
{

class OperationControllerVisitor;

class LocalMoveController final : public MoveController, public LocalController
{
public:
   LocalMoveController(Models::Game& game);
   ~LocalMoveController();

   LocalMoveController(const LocalMoveController&) = delete;
   LocalMoveController& operator=(const LocalMoveController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   void move();
};

}

#endif
