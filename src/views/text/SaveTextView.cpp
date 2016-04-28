
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
   bool askAgain;
   do
   {
      Utils::IO& io = Utils::IO::getInstance();
      saveFileNameM = io.readString("Write now the name of the file you want to save");
      if (saveController->fileAlreadyExists(saveFileNameM))
         askAgain = not Utils::YesNoDialog("File already exist. Do you want to override").read();
      else
         askAgain = false;
   } while (askAgain);
}

}
