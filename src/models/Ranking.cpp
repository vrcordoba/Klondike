
#include "Ranking.hpp"
#include "KlondikeConfiguration.hpp"
#include "PermanentMedium.hpp"
#include "PermanentMediumReader.hpp"
#include "PermanentMediumWriter.hpp"
#include "PermanentMediumPrototyper.hpp"

namespace Models
{

Ranking::Ranking(std::string rankingFile) : rankingM(), rankingFileM(rankingFile)
{
}

Ranking::~Ranking()
{
}

std::uint32_t Ranking::insertInRanking(std::uint32_t currentScore)
{
   loadRanking();
   std::uint32_t positionInRanking = 1;
   for (std::vector<std::uint32_t>::iterator rankingIt = rankingM.begin();
      rankingIt != rankingM.end(); ++rankingIt)
   {
      if (currentScore > *rankingIt)
      {
         rankingM.insert(rankingIt, currentScore);
         rankingIt = rankingM.end();
         rankingM.erase(--rankingIt);
         break;
      }
      ++positionInRanking;
   }
   return positionInRanking;
}

void Ranking::loadRanking()
{
   Utils::PermanentMediumReader* rankingReader =
      Utils::PermanentMediumPrototyper().getReader(
         Configuration::KlondikeConfiguration::getInstance().getPermanentMediumType());
   rankingReader->open(rankingFileM);
   if (rankingReader->isOk())
   {
      bool continueReading;
      do
      {
         std::string score;
         continueReading = rankingReader->getField(score);
         if (not score.empty())
            rankingM.push_back(atoi(score.c_str()));
      } while (continueReading);
   }
   delete rankingReader;
}

void Ranking::saveRanking()
{
   Utils::PermanentMediumWriter* rankingWriter =
      Utils::PermanentMediumPrototyper().getWriter(
         Utils::PermanentMedium::Type::PLAIN_TEXT);
   rankingWriter->open(rankingFileM);
   if (rankingWriter->isOk())
   {
      std::vector<std::uint32_t>::const_iterator rankingIt = rankingM.begin();
      for (std::uint8_t i = 0; i < SCORES_TO_SAVE; ++i)
      {
         rankingWriter->writeField(std::to_string(*rankingIt));
         ++rankingIt;
      }
   }
   delete rankingWriter;
}

std::vector<std::uint32_t> Ranking::bestScores()
{
   return rankingM;
}

}
