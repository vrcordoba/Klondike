#ifndef CONTROLLERS_CARDTABLECONTROLLER_HPP_
#define CONTROLLERS_CARDTABLECONTROLLER_HPP_

#include <cstdint>
#include <vector>
#include "Controller.hpp"
#include "FacadeCard.hpp"

namespace Models
{
class Pile;
class Game;
}

namespace Controllers
{

class CardTableController final : public Controller
{
public:
   explicit CardTableController(Models::Game& game);
   ~CardTableController();

   CardTableController(const CardTableController&) = delete;
   CardTableController& operator=(const CardTableController&) = delete;

   std::vector<FacadeCard> getDeck();
   std::vector<FacadeCard> getWaste();
   std::vector<FacadeCard> getTableau(std::uint8_t i);
   std::vector<FacadeCard> getFoundation(std::uint8_t i);
   std::uint8_t getNumTableaus() const;
   std::uint8_t getNumFoundations() const;

   std::uint32_t getScore();

private:
   std::vector<FacadeCard> getFacadePile(const Models::Pile* pile);
};

}

#endif
