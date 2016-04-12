#ifndef CONTROLLERS_LOCAL_LOCALCONTINUECONTROLLER_HPP_
#define CONTROLLERS_LOCAL_LOCALCONTINUECONTROLLER_HPP_

#include "ContinueController.hpp"
#include "LocalController.hpp"

namespace Models
{
   class Game;
}

namespace Controllers
{

class OperationControllerVisitor;

class LocalContinueController: public ContinueController, public LocalController
{
public:
   explicit LocalContinueController(Models::Game& game);
   ~LocalContinueController();

   LocalContinueController(const LocalContinueController&) = delete;
   LocalContinueController& operator=(const LocalContinueController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   void resume(bool otherGame);
};

}

#endif
