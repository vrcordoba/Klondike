
cmake_minimum_required(VERSION 2.8.11)
project(Klondike)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/controllers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/controllers/local)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/models)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/views)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/views/text)

set(HEADER_FILES
   Klondike.hpp

   controllers/OperationController.hpp
   controllers/OperationControllerVisitor.hpp
   controllers/StartController.hpp
   controllers/MoveController.hpp
   controllers/ContinueController.hpp
   controllers/CardTableController.hpp
   controllers/local/Logic.hpp
   controllers/local/LocalController.hpp
   controllers/local/LocalStartController.hpp
   controllers/local/LocalMoveController.hpp
   controllers/local/LocalContinueController.hpp
   controllers/local/LocalCardTableController.hpp

   models/Suit.hpp
   models/Card.hpp
   models/Pile.hpp
   models/Deck.hpp
   models/SpanishDeck.hpp
   models/FrenchDeck.hpp
   models/MovementDestination.hpp
   models/Foundation.hpp
   models/Tableau.hpp
   models/CardTable.hpp
   models/State.hpp
   models/Game.hpp
   models/DeckType.hpp
   models/DeckBuilder.hpp
   models/Movement.hpp
   models/MovementHistory.hpp

   utils/ClosedInterval.hpp
   utils/IO.hpp
   utils/LimitedIntDialog.hpp
   utils/YesNoDialog.hpp
   utils/TextMenu.hpp

   views/KlondikeView.hpp
   views/StartView.hpp
   views/GameView.hpp
   views/ContinueView.hpp
   views/CardTableView.hpp
   views/CardView.hpp
   views/text/KlondikeTextView.hpp
   views/text/StartTextView.hpp
   views/text/GameTextView.hpp
   views/text/ContinueTextView.hpp
   views/text/CardTableTextView.hpp
   views/text/CardTextViewBuilder.hpp
   views/text/CardTextView.hpp
   views/text/FrenchCardTextView.hpp
   views/text/SpanishCardTextView.hpp
)

set(SOURCE_FILES
   main.cpp
   Klondike.cpp

   controllers/local/Logic.cpp
   controllers/local/LocalController.cpp
   controllers/local/LocalStartController.cpp
   controllers/local/LocalMoveController.cpp
   controllers/local/LocalContinueController.cpp
   controllers/local/LocalCardTableController.cpp

   models/Suit.cpp
   models/Card.cpp
   models/Pile.cpp
   models/Deck.cpp
   models/SpanishDeck.cpp
   models/FrenchDeck.cpp
   models/Foundation.cpp
   models/Tableau.cpp
   models/CardTable.cpp
   models/Game.cpp
   models/DeckType.cpp
   models/DeckBuilder.cpp
   models/Movement.cpp
   models/MovementHistory.cpp

   utils/ClosedInterval.cpp
   utils/IO.cpp
   utils/LimitedIntDialog.cpp
   utils/YesNoDialog.cpp
   utils/TextMenu.cpp

   views/text/KlondikeTextView.cpp
   views/text/StartTextView.cpp
   views/text/GameTextView.cpp
   views/text/ContinueTextView.cpp
   views/text/CardTableTextView.cpp
   views/text/CardTextViewBuilder.cpp
   views/text/CardTextView.cpp
   views/text/FrenchCardTextView.cpp
   views/text/SpanishCardTextView.cpp
)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -g2")

add_executable(klondike ${HEADER_FILES} ${SOURCE_FILES})
