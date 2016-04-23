#ifndef MODELS_SCORE_HPP_
#define MODELS_SCORE_HPP_

#include <cstdint>

namespace Models
{

class Score final
{
public:
   Score();
   ~Score();

   Score(const Score&) = delete;
   Score& operator=(const Score&) = delete;

   void rebootScore();
   void movementScore(std::uint8_t originPileId, std::uint8_t destinationPileId,
      std::uint8_t numCards);
   void turnOverTableauCardScore();
   std::uint32_t getScore() const;

private:
   void computeScoreOriginFoundation(std::uint8_t destinationPileId);
   void computeScoreOriginTableau(std::uint8_t destinationPileId, std::uint8_t numCards);
   void computeScoreOriginWaste(std::uint8_t destinationPileId);

   std::uint32_t scoreM;
};

}

#endif
