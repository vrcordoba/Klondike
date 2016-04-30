
#include "DeckPrototyper.hpp"

#include <cassert>
#include <algorithm>
#include "KlondikeConfiguration.hpp"
#include "SpanishDeck.hpp"
#include "FrenchDeck.hpp"

namespace Models
{

DeckPrototyper::DeckPrototyper()
{
   deckPrototypesM.emplace(Configuration::DeckType::Type::SPANISH, new SpanishDeck());
   deckPrototypesM.emplace(Configuration::DeckType::Type::FRENCH, new FrenchDeck());
}

DeckPrototyper::~DeckPrototyper()
{
   std::for_each(std::begin(deckPrototypesM), std::end(deckPrototypesM),
      [] (std::pair<const Configuration::DeckType::Type, Deck*>& pair)
      {
         delete pair.second;
      });
}

Deck* DeckPrototyper::getDeck(Configuration::DeckType::Type deckType)
{
   std::map<Configuration::DeckType::Type, Deck*>::const_iterator deckIt =
      deckPrototypesM.find(deckType);
   assert(deckIt != deckPrototypesM.end());
   Configuration::KlondikeConfiguration::getInstance().setDeckType(deckType);
   Deck* deck = deckIt->second->clone();
   return deck;
}

}
