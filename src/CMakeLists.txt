
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

   models/Deck.hpp

   utils/Card.hpp

   views/KlondikeView.hpp
)

set(SOURCE_FILES
   main.cpp
   Klondike.cpp

   controllers/local/LocalOperationController.cpp
   controllers/local/Logic.cpp

   models/Deck.cpp

   utils/Card.cpp

   views/KlondikeView.cpp
)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

add_executable(klondike ${HEADER_FILES} ${SOURCE_FILES})
