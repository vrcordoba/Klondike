
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

add_executable(DeckTests DeckTests.cpp ../src/models/Deck.cpp ../src/models/Deck.hpp ../src/utils/Card.cpp ../src/utils/Card.hpp)
target_link_libraries(DeckTests ${GTEST_LIBRARIES} pthread)

add_executable(ClosedIntervalTests ClosedIntervalTests.cpp ../src/utils/ClosedInterval.cpp ../src/utils/ClosedInterval.hpp)
target_link_libraries(ClosedIntervalTests ${GTEST_LIBRARIES} pthread)