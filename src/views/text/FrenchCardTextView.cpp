
#include "FrenchCardTextView.hpp"

namespace Views
{

FrenchCardTextView::FrenchCardTextView()
{
}

FrenchCardTextView::~FrenchCardTextView()
{
}

void FrenchCardTextView::constructRepresentation()
{
   numberRepresentationM.push_back("1");
   numberRepresentationM.push_back("2");
   numberRepresentationM.push_back("3");
   numberRepresentationM.push_back("4");
   numberRepresentationM.push_back("5");
   numberRepresentationM.push_back("6");
   numberRepresentationM.push_back("7");
   numberRepresentationM.push_back("8");
   numberRepresentationM.push_back("9");
   numberRepresentationM.push_back("10");
   numberRepresentationM.push_back("J");
   numberRepresentationM.push_back("Q");
   numberRepresentationM.push_back("K");

   suitRepresentationM.push_back(SPADE);
   suitRepresentationM.push_back(DIAMOND);
   suitRepresentationM.push_back(CLUB);
   suitRepresentationM.push_back(HEART);
}

}
