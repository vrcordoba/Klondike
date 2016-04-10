#ifndef MODELS_CARDTABLE_HPP_
#define MODELS_CARDTABLE_HPP_

#include <vector>
#include "Foundation.hpp"
#include "Pile.hpp"
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

   Deck& getDeck();
   Pile& getWaste();
   Tableau& getTableau(std::uint8_t tableauIndex);
   Foundation& getFoundation(std::uint8_t foundationIndex);

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
