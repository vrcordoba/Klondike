
#include "ContinueTextView.hpp"

#include "IO.hpp"
#include "YesNoDialog.hpp"
#include "ContinueController.hpp"

namespace Views
{

ContinueTextView::ContinueTextView()
{
}

ContinueTextView::~ContinueTextView()
{
}

void ContinueTextView::interact(Controllers::ContinueController* continueController)
{
   std::uint32_t positionInRanking;
   std::vector<std::uint32_t> bestScores;
   continueController->ranking(positionInRanking, bestScores);
   showRanking(positionInRanking, bestScores);
   Utils::YesNoDialog dialog("Do you want to play again");
   continueController->resume(dialog.read());
}

void ContinueTextView::showRanking(std::uint32_t positionInRanking,
   const std::vector<std::uint32_t>& bestScores)
{
   std::uint32_t i = 1;
   Utils::IO& io = Utils::IO::getInstance();
   io.writeString("Best scores:");
   for (std::uint32_t score : bestScores)
   {
      if (positionInRanking == i)
         io.writeString(std::to_string(i) + " - >>> " + std::to_string(score) + " <<< Your score");
      else
         io.writeString(std::to_string(i) + " - " + std::to_string(score));
      ++i;
   }
}

}
