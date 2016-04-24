#ifndef MODELS_RANKING_HPP_
#define MODELS_RANKING_HPP_

#include <cstdint>
#include <set>
#include <string>

namespace Models
{

class Ranking
{
public:
   explicit Ranking(std::string rankingFile);
   ~Ranking();

   std::uint32_t insertInRanking(std::uint32_t currentScore);
   std::set<std::uint32_t> bestScores();

   void saveRanking();

private:
   void loadRanking();

   std::set<std::uint32_t> rankingM;
   std::string rankingFileM;
   const std::uint32_t SCORES_TO_SAVE = 10;
};

}

#endif
