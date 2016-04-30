
#include "LoadTextView.hpp"

#include "IO.hpp"
#include "LoadController.hpp"

namespace Views
{

LoadTextView::LoadTextView()
{
}

LoadTextView::~LoadTextView()
{
}

void LoadTextView::interact(Controllers::LoadController* loadController)
{
   std::string saveFileName = askForName(loadController);
   loadController->load(saveFileName);
}

std::string LoadTextView::askForName(Controllers::LoadController* loadController)
{
   std::string saveFileName;
   bool askAgain;
   do
   {
      Utils::IO& io = Utils::IO::getInstance();
      saveFileName = io.readString("Write now the name of the file you want to load");
      if (not loadController->fileAlreadyExists(saveFileName))
      {
         io.writeString("File does not exist");
         askAgain = true;
      }
      else
         askAgain = false;
   } while (askAgain);
   return saveFileName;
}

}
