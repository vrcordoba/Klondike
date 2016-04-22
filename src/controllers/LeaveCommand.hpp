#ifndef CONTROLLERS_LEAVECOMMAND_HPP_
#define CONTROLLERS_LEAVECOMMAND_HPP_

#include <cstdint>
#include "Command.hpp"

namespace Controllers
{

class LeaveCommand final : public Command
{
public:
   enum class Type : std::uint8_t
   {
      LEAVE_CLOSE,
      LEAVE_RESTART
   };

   explicit LeaveCommand(Type type);
   ~LeaveCommand();

   LeaveCommand(const LeaveCommand&) = delete;
   LeaveCommand& operator=(const LeaveCommand&) = delete;

   bool accept(CommandVisitor* commandVisitor);

   Type getType() const;

private:
   Type typeM;
};

}

#endif
