
#include "Score.hpp"

#include "PileType.hpp"

namespace Models
{

Score::Score() : scoreM(0)
{
}

Score::~Score()
{
}

void Score::rebootScore()
{
   scoreM = 0;
}

std::uint32_t Score::getScore() const
{
   return scoreM;
}

void Score::movementScore(std::uint8_t originPileId, std::uint8_t destinationPileId,
   std::uint8_t numCards, bool negativeScore)
{
   if (PileType::FOUNDATION == originPileId)
      computeScoreOriginFoundation(destinationPileId, negativeScore);
   else if (PileType::TABLEAU == originPileId)
      computeScoreOriginTableau(destinationPileId, numCards, negativeScore);
   else if (PileType::WASTE == originPileId)
      computeScoreOriginWaste(destinationPileId, negativeScore);
}

void Score::computeScoreOriginFoundation(std::uint8_t destinationPileId,
   bool negativeScore)
{
   std::int32_t coef = negativeScore ? -1 : 1;
   if (PileType::TABLEAU == destinationPileId)
   {
      if (not negativeScore and scoreM < 15)
         rebootScore();
      else
         scoreM -= 15 * coef;
   }
}

void Score::computeScoreOriginTableau(std::uint8_t destinationPileId,
   std::uint8_t numCards, bool negativeScore)
{
   std::int32_t coef = negativeScore ? -1 : 1;
   if (PileType::FOUNDATION == destinationPileId)
      scoreM += 10 * numCards * coef;
}

void Score::computeScoreOriginWaste(std::uint8_t destinationPileId, bool negativeScore)
{
   std::int32_t coef = negativeScore ? -1 : 1;
   if (PileType::TABLEAU == destinationPileId)
      scoreM += 5 * coef;
   else if (PileType::FOUNDATION == destinationPileId)
      scoreM += 10 * coef;
}

void Score::turnOverTableauCardScore(bool negativeScore)
{
   std::int32_t coef = negativeScore ? -1 : 1;
   scoreM += 5 * coef;
}

}
