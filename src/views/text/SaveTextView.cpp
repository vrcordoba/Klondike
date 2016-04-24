
#include "SaveTextView.hpp"

#include "SaveController.hpp"
#include "IO.hpp"
#include "YesNoDialog.hpp"

namespace Views
{

SaveTextView::SaveTextView() : saveFileNameM()
{
}

SaveTextView::~SaveTextView()
{
}

void SaveTextView::interact(Controllers::SaveController* saveController)
{
   if (saveFileNameM.empty())
   {
      askForName(saveController);
   }
   saveController->saveGame(saveFileNameM);
}

void SaveTextView::askForName(Controllers::SaveController* saveController)
{
   bool askAgain = false;
   do
   {
      Utils::IO& io = Utils::IO::getInstance();
      io.writeString("Write now the name of the file you want to save");
      io.readString(saveFileNameM);
      if (saveController->fileAlreadyExists(saveFileNameM))
         askAgain = not Utils::YesNoDialog("File already exist. Do you want to override?").read();
   } while (askAgain);
}

}
