
#include "SpanishCardTextView.hpp"
#include "IO.hpp"

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

   suitRepresentationM.push_back("Oros");
   suitRepresentationM.push_back("Copas");
   suitRepresentationM.push_back("Espadas");
   suitRepresentationM.push_back("Bastos");
}

}
