
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

void Score::movementScore(std::uint8_t originPileId, std::uint8_t destinationPileId)
{
   if (PileType::FOUNDATION == originPileId)
      computeScoreOriginFoundation(destinationPileId);
   else if (PileType::TABLEAU == originPileId)
      computeScoreOriginTableau(destinationPileId);
   else if (PileType::WASTE == originPileId)
      computeScoreOriginWaste(destinationPileId);
}

void Score::computeScoreOriginFoundation(std::uint8_t destinationPileId)
{
   if (PileType::TABLEAU == destinationPileId)
   {
      if (scoreM > 15)
         scoreM -= 15;
      else
         rebootScore();
   }
}

void Score::computeScoreOriginTableau(std::uint8_t destinationPileId)
{
   if (PileType::FOUNDATION == destinationPileId)
      scoreM += 10;
}

void Score::computeScoreOriginWaste(std::uint8_t destinationPileId)
{
   if (PileType::TABLEAU == destinationPileId)
      scoreM += 5;
   else if (PileType::FOUNDATION == destinationPileId)
      scoreM += 10;
}

void Score::turnOverTableauCardScore()
{
   scoreM += 5;
}

}
