#ifndef MODELS_RANKING_HPP_
#define MODELS_RANKING_HPP_

#include <cstdint>
#include <vector>
#include <string>

namespace Models
{

class Ranking
{
public:
   explicit Ranking(std::string rankingFile);
   ~Ranking();

   std::uint32_t insertInRanking(std::uint32_t currentScore);
   std::vector<std::uint32_t> bestScores();

   void saveRanking();

private:
   void loadRanking();

   std::vector<std::uint32_t> rankingM;
   std::string rankingFileM;
   const std::uint32_t SCORES_TO_SAVE = 10;
};

}

#endif
