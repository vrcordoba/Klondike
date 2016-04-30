#ifndef CONTROLLERS_LOADCONTROLLER_HPP_
#define CONTROLLERS_LOADCONTROLLER_HPP_

#include <string>
#include "Controller.hpp"
#include "OperationController.hpp"

namespace Utils
{
class PermanentMediumReader;
}

namespace Models
{
class Game;
class Pile;
}

namespace Controllers
{

class OperationControllerVisitor;

class LoadController final : public Controller, public OperationController
{
public:
   explicit LoadController(Models::Game& game);
   ~LoadController();

   LoadController(const LoadController&) = delete;
   LoadController& operator=(const LoadController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   bool fileAlreadyExists(const std::string& saveFileName);
   void load(const std::string& saveFileName);

private:
   void loadPile(Utils::PermanentMediumReader* saveFile, Models::Pile* pile);
};

}

#endif
