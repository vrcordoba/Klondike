#ifndef CONTROLLERS_CONTINUECONTROLLER_HPP_
#define CONTROLLERS_CONTINUECONTROLLER_HPP_

#include <cstdint>
#include <set>
#include <string>
#include "Controller.hpp"
#include "OperationController.hpp"

namespace Models
{
class Game;
}

namespace Controllers
{

class OperationControllerVisitor;

class ContinueController: public Controller, public OperationController
{
public:
   explicit ContinueController(Models::Game& game);
   ~ContinueController();

   ContinueController(const ContinueController&) = delete;
   ContinueController& operator=(const ContinueController&) = delete;

   void accept(OperationControllerVisitor* operationControllerVisitor);

   void ranking(std::uint32_t& position, std::set<std::uint32_t>& bestScores);

   void resume(bool otherGame);

private:
   const std::string RANKING_FILE = "ranking";
};

}

#endif
