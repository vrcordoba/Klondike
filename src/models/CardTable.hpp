#ifndef MODELS_CARDTABLE_HPP_
#define MODELS_CARDTABLE_HPP_

#include <vector>
#include "Pile.hpp"
#include "Foundation.hpp"
#include "Tableau.hpp"

namespace Models
{

class Deck;

class CardTable final
{
public:
   CardTable(Deck& deck, std::uint8_t numTableaus);
   ~CardTable();

   CardTable(const CardTable&) = delete;
   CardTable& operator=(const CardTable&) = delete;

   void transferCard(Pile& originPile, Pile& destinationPile);

   bool isGameWon() const;

   Pile& getDeck();
   Pile& getWaste();
   Pile& getTableau(std::uint8_t tableauIndex);
   Pile& getFoundation(std::uint8_t foundationIndex);

   std::uint8_t getNumSuits() const;

private:
   void buildTableaus(std::uint8_t numTableaus);
   void buildFoundations();

   Deck& deckM;
   Pile wasteM;
   std::vector<Tableau> tableausM;
   std::vector<Foundation> foundationsM;
};

}

#endif
