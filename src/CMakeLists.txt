
cmake_minimum_required(VERSION 2.8.11)
project(Klondike)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/controllers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/controllers/local)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/models)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/views)

set(HEADER_FILES
   Klondike.hpp

   controllers/OperationController.hpp
   controllers/local/LocalOperationController.hpp
   controllers/local/Logic.hpp

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

   utils/ClosedInterval.hpp
   utils/IO.hpp
   utils/LimitedIntDialog.hpp
   utils/YesNoDialog.hpp

   views/KlondikeView.hpp
)

set(SOURCE_FILES
   main.cpp
   Klondike.cpp

   controllers/local/LocalOperationController.cpp
   controllers/local/Logic.cpp

   models/Suit.cpp
   models/Card.cpp
   models/Pile.cpp
   models/Deck.cpp
   models/SpanishDeck.cpp
   models/FrenchDeck.cpp
   models/Foundation.cpp
   models/Tableau.cpp
   models/CardTable.cpp

   utils/ClosedInterval.cpp
   utils/IO.cpp
   utils/LimitedIntDialog.cpp
   utils/YesNoDialog.cpp

   views/KlondikeView.cpp
)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

add_executable(klondike ${HEADER_FILES} ${SOURCE_FILES})
