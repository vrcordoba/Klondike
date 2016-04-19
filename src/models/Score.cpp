
#include "Score.hpp"

#include "MovementOriginDestinationType.hpp"

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
   if (MovementOriginDestinationType::FOUNDATION == originPileId)
      computeScoreOriginFoundation(destinationPileId);
   else if (MovementOriginDestinationType::TABLEAU == originPileId)
      computeScoreOriginTableau(destinationPileId);
   else if (MovementOriginDestinationType::WASTE == originPileId)
      computeScoreOriginWaste(destinationPileId);
}

void Score::computeScoreOriginFoundation(std::uint8_t destinationPileId)
{
   if (MovementOriginDestinationType::TABLEAU == destinationPileId)
   {
      if (scoreM > 15)
         scoreM -= 15;
      else
         rebootScore();
   }
}

void Score::computeScoreOriginTableau(std::uint8_t destinationPileId)
{
   if (MovementOriginDestinationType::FOUNDATION == destinationPileId)
      scoreM += 10;
}

void Score::computeScoreOriginWaste(std::uint8_t destinationPileId)
{
   if (MovementOriginDestinationType::TABLEAU == destinationPileId)
      scoreM += 5;
   else if (MovementOriginDestinationType::FOUNDATION == destinationPileId)
      scoreM += 10;
}

void Score::turnOverTableauCardScore()
{
   scoreM += 5;
}

void Score::recycleWasteScore()
{
   if (scoreM > 100)
      scoreM -= 100;
   else
      rebootScore();
}

}
