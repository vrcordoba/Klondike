
#include "MoveController.hpp"

#include "MoveCommand.hpp"
#include "DrawCardCommand.hpp"
#include "Score.hpp"
#include "Pile.hpp"

namespace Controllers
{

MoveController::MoveController(Models::Game& game)
   : Controller(game), movementHistoryM()
{
}

MoveController::~MoveController()
{
}

bool MoveController::isValidMovement(MoveCommand* command)
{
   command->setController(this);
   return command->isValidOrigin() and command->isValidDestination();
}

void MoveController::applyMovement(MoveCommand* command)
{
   movementHistoryM.storeAndExecute(command);
   Models::Pile* originPile = command->getPile(command->getOriginPileType(),
      command->getOriginPileNumber());
   if (originPile->getNumCards() > 0 and not originPile->isTopCardUnturned())
   {
      originPile->setUpturnCards(1, true);
      updateScore(command, true);
   }
   else
      updateScore(command, false);
}

void MoveController::updateScore(MoveCommand* command, bool upturnScore)
{
   Models::Score& score = Controller::getScore();
   if (upturnScore)
      score.turnOverTableauCardScore();
   score.movementScore(command->getOriginPileType(),
      command->getDestinationPileType(), command->getNumCards());
}

void MoveController::applyDrawCard(DrawCardCommand* command)
{
   command->setController(this);
   movementHistoryM.storeAndExecute(command);
}

bool MoveController::validateUndo() const
{
   return movementHistoryM.validateUndo();
}

bool MoveController::validateRedo() const
{
   return movementHistoryM.validateRedo();
}

void MoveController::undo()
{
   movementHistoryM.undo();
}

void MoveController::redo()
{
   movementHistoryM.redo();
}


}
