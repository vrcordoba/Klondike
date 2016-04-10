
cmake_minimum_required(VERSION 2.8.11)
project(KlondikeTests)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/controllers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/controllers/local)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/models)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/utils)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/views)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(ClosedIntervalTests ClosedIntervalTests.cpp
   ../src/utils/ClosedInterval.cpp ../src/utils/ClosedInterval.hpp)
target_link_libraries(ClosedIntervalTests ${GTEST_LIBRARIES} pthread)

add_executable(SuitTests SuitTests.cpp
   ../src/models/Suit.cpp ../src/models/Suit.hpp)
target_link_libraries(SuitTests ${GTEST_LIBRARIES} pthread)

add_executable(CardTests CardTests.cpp
   ../src/models/Suit.cpp ../src/models/Suit.hpp
   ../src/models/Card.cpp ../src/models/Card.hpp)
target_link_libraries(CardTests ${GTEST_LIBRARIES} pthread)

add_executable(DeckTests DeckTests.cpp
   ../src/utils/ClosedInterval.cpp ../src/utils/ClosedInterval.hpp
   ../src/models/Suit.cpp ../src/models/Suit.hpp
   ../src/models/Card.cpp ../src/models/Card.hpp
   ../src/models/Pile.cpp ../src/models/Pile.hpp
   ../src/models/Deck.cpp ../src/models/Deck.hpp
   ../src/models/FrenchDeck.cpp ../src/models/FrenchDeck.hpp
   ../src/models/SpanishDeck.cpp ../src/models/SpanishDeck.hpp)
target_link_libraries(DeckTests ${GTEST_LIBRARIES} pthread)

add_executable(FoundationTests FoundationTests.cpp
   ../src/utils/ClosedInterval.cpp ../src/utils/ClosedInterval.hpp
   ../src/models/Suit.cpp ../src/models/Suit.hpp
   ../src/models/Card.cpp ../src/models/Card.hpp
   ../src/models/Pile.cpp ../src/models/Pile.hpp
   ../src/models/Deck.cpp ../src/models/Deck.hpp
   ../src/models/FrenchDeck.cpp ../src/models/FrenchDeck.hpp
   ../src/models/MovementDestination.hpp
   ../src/models/Foundation.cpp ../src/models/Foundation.hpp)
target_link_libraries(FoundationTests ${GTEST_LIBRARIES} pthread)

add_executable(TableauTests TableauTests.cpp
   ../src/utils/ClosedInterval.cpp ../src/utils/ClosedInterval.hpp
   ../src/models/Suit.cpp ../src/models/Suit.hpp
   ../src/models/Card.cpp ../src/models/Card.hpp
   ../src/models/Pile.cpp ../src/models/Pile.hpp
   ../src/models/Deck.cpp ../src/models/Deck.hpp
   ../src/models/SpanishDeck.cpp ../src/models/SpanishDeck.hpp
   ../src/models/MovementDestination.hpp
   ../src/models/Tableau.cpp ../src/models/Tableau.hpp)
target_link_libraries(TableauTests ${GTEST_LIBRARIES} pthread)

add_executable(CardTableTests CardTableTests.cpp
   ../src/utils/ClosedInterval.cpp ../src/utils/ClosedInterval.hpp
   ../src/models/Suit.cpp ../src/models/Suit.hpp
   ../src/models/Deck.cpp ../src/models/Deck.hpp
   ../src/models/Tableau.cpp ../src/models/Tableau.hpp
   ../src/models/Card.cpp ../src/models/Card.hpp
   ../src/models/Pile.cpp ../src/models/Pile.hpp
   ../src/models/Foundation.cpp ../src/models/Foundation.hpp
   ../src/models/SpanishDeck.cpp ../src/models/SpanishDeck.hpp
   ../src/models/MovementDestination.hpp
   ../src/models/CardTable.cpp ../src/models/CardTable.hpp)
target_link_libraries(CardTableTests ${GTEST_LIBRARIES} pthread)

add_executable(GameTests GameTests.cpp
   ../src/utils/ClosedInterval.cpp ../src/utils/ClosedInterval.hpp
   ../src/models/Suit.cpp ../src/models/Suit.hpp
   ../src/models/Deck.cpp ../src/models/Deck.hpp
   ../src/models/Tableau.cpp ../src/models/Tableau.hpp
   ../src/models/Card.cpp ../src/models/Card.hpp
   ../src/models/Pile.cpp ../src/models/Pile.hpp
   ../src/models/Foundation.cpp ../src/models/Foundation.hpp
   ../src/models/FrenchDeck.cpp ../src/models/FrenchDeck.hpp
   ../src/models/MovementDestination.hpp
   ../src/models/CardTable.cpp ../src/models/CardTable.hpp
   ../src/models/State.hpp
   ../src/models/Movement.cpp ../src/models/Movement.hpp
   ../src/models/MovementHistory.cpp ../src/models/MovementHistory.hpp
   ../src/models/Game.cpp ../src/models/Game.hpp)
target_link_libraries(GameTests ${GTEST_LIBRARIES} pthread)


