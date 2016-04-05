#ifndef MODELS_CARDTABLE_HPP_
#define MODELS_CARDTABLE_HPP_

#include "Pile.hpp"
#include <vector>
#include "Tableau.hpp"
#include <list>
#include "Foundation.hpp"
#include <cstdint>

namespace Models
{

class Deck;

class CardTable final
{
public:
   CardTable(const Deck& deck, std::uint8_t numTableaus);
   ~CardTable();

   CardTable(const CardTable&) = delete;
   CardTable& operator=(const CardTable&) = delete;

private:
   void buildTableaus(std::uint8_t numTableaus);

   const Deck& deckM;
   Pile wasteM;
   std::vector<Tableau> tableausM;
   std::list<Foundation> foundationsM;
};

}

#endif
