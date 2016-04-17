
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

   suitRepresentationM.push_back("\u2660"); // Spades
   suitRepresentationM.push_back("\u2666"); // Diamonds
   suitRepresentationM.push_back("\u2663"); // Clubs
   suitRepresentationM.push_back("\u2665"); // Hearts
}

}
