#ifndef CONFIGURATION_CONTROLLERTYPE_HPP_
#define CONFIGURATION_CONTROLLERTYPE_HPP_

#include <cstdint>

namespace Configuration
{

enum class ControllerType : std::uint8_t
{
   LOCAL,
   REMOTE
};

}

#endif
