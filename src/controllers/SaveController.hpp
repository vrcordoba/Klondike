#ifndef CONTROLLERS_SAVECONTROLLER_HPP_
#define CONTROLLERS_SAVECONTROLLER_HPP_

#include <string>
#include "Controller.hpp"
#include "OperationController.hpp"

namespace Models
{
class Game;
class Pile;
}

namespace Utils
{
class PermanentMediumWriter;
}

namespace Controllers
{

class OperationControllerVisitor;

class SaveController final : public Controller, public OperationController
{
public:
   explicit SaveController(Models::Game& game);
   ~SaveController();

   SaveController(const SaveController&) = delete;
   SaveController& operator=(const SaveController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   bool fileAlreadyExists(const std::string& saveFileName);
   void saveGame(const std::string& saveFileName);

private:
   void saveCardTable(Utils::PermanentMediumWriter* saveFile);
   void savePile(Utils::PermanentMediumWriter* saveFile, Models::Pile* pile);
};

}

#endif
