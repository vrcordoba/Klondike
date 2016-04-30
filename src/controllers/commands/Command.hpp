#ifndef CONTROLLERS_COMMANDS_COMMAND_HPP_
#define CONTROLLERS_COMMANDS_COMMAND_HPP_

namespace Controllers
{

class GameController;

class Command
{
public:
   Command();
   virtual ~Command();

   virtual Command* clone() = 0;

   virtual void execute() = 0;

   void setController(GameController* controller);
   GameController* getController() const;

   virtual bool doesItHaveToBeValidated();
   virtual bool isUndoable();

protected:
   GameController* gameControllerM;
};

}

#endif
