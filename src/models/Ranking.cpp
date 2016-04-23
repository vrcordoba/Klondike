
#include "Ranking.hpp"
#include "PermanentMediumReader.hpp"
#include "PermanentMediumReaderPrototyper.hpp"

namespace Models
{

Ranking::Ranking(std::string rankingFile) : rankingM(), rankingFileM(rankingFile)
{
}

Ranking::~Ranking()
{
}

std::uint32_t Ranking::obtainPositionInRanking(std::uint32_t currentScore)
{
   readRanking();
   std::uint32_t positionInRanking = 1;
   for (std::uint32_t score : rankingM)
   {
      if (currentScore > score)
         break;
      positionInRanking++;
   }
   rankingM.insert(currentScore);
   return positionInRanking;
}

void Ranking::readRanking()
{
   Utils::PermanentMediumReader* rankingReader =
      Utils::PermanentMediumReaderPrototyper::makePrototype(Utils::PermanentMediumReaderPrototyper::PLAIN_TEXT);
   rankingReader->open(rankingFileM);
   if (rankingReader->isOk())
   {
      bool continueReading;
      do
      {
         std::string score;
         continueReading = rankingReader->getLine(score);
         if (not score.empty())
            rankingM.insert((atoi(score.c_str())));
      } while (continueReading);
   }
}

}
