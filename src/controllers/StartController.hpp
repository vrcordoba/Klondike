#ifndef CONTROLLERS_STARTCONTROLLER_HPP_
#define CONTROLLERS_STARTCONTROLLER_HPP_

#include <cstdint>
#include <list>
#include <string>
#include "OperationController.hpp"

namespace Controllers
{

class StartController : public OperationController
{
public:
   virtual ~StartController() {};
   virtual void start(std::uint8_t numPlayers, std::uint8_t newOrSavedOption,
      std::uint8_t typeDeck) = 0;
   virtual std::list<std::string> getDeckDescriptions() const = 0;
};

}

#endif
