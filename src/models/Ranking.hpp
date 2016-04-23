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

private:
   std::uint32_t obtainPositionInRanking(std::uint32_t currentScore);
   void readRanking();

   std::set<std::uint32_t> rankingM;
   std::string rankingFileM;
};

}

#endif
