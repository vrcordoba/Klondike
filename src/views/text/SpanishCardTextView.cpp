
#include "SpanishCardTextView.hpp"

namespace Views
{

SpanishCardTextView::SpanishCardTextView()
{
}

SpanishCardTextView::~SpanishCardTextView()
{
}

void SpanishCardTextView::constructRepresentation()
{
   numberRepresentationM.push_back("1");
   numberRepresentationM.push_back("2");
   numberRepresentationM.push_back("3");
   numberRepresentationM.push_back("4");
   numberRepresentationM.push_back("5");
   numberRepresentationM.push_back("6");
   numberRepresentationM.push_back("7");
   numberRepresentationM.push_back("Sota");
   numberRepresentationM.push_back("Caballo");
   numberRepresentationM.push_back("Rey");

   suitRepresentationM.push_back("\033[0;33mOros");
   suitRepresentationM.push_back("\033[0;31mCopas");
   suitRepresentationM.push_back("\033[0;36mEspadas");
   suitRepresentationM.push_back("\033[0;32mBastos");
}

}
