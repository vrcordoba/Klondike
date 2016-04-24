
cmake_minimum_required(VERSION 2.8.11)
project(Klondike)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/configuration)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/controllers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/models)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/views)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/views/text)

set(HEADER_FILES
   Klondike.hpp

   configuration/KlondikeConfiguration.hpp
   configuration/DeckType.hpp
   configuration/ViewType.hpp

   controllers/OperationController.hpp
   controllers/OperationControllerVisitor.hpp
   controllers/FacadeCard.hpp
   controllers/Logic.hpp
   controllers/Controller.hpp
   controllers/StartController.hpp
   controllers/GameController.hpp
   controllers/ContinueController.hpp
   controllers/CardTableController.hpp
   controllers/CommandType.hpp
   controllers/Command.hpp
   controllers/CardCommand.hpp
   controllers/DrawCardCommand.hpp
   controllers/MoveCommand.hpp
   controllers/LeaveCommand.hpp
   controllers/ModifyHistoryCommand.hpp
   controllers/MoveController.hpp
   controllers/MovementHistory.hpp
   controllers/CommandManager.hpp
   controllers/CommandVisitor.hpp

   models/Suit.hpp
   models/Card.hpp
   models/Pile.hpp
   models/Deck.hpp
   models/SpanishDeck.hpp
   models/FrenchDeck.hpp
   models/Foundation.hpp
   models/Tableau.hpp
   models/CardTable.hpp
   models/State.hpp
   models/Game.hpp
   models/DeckManager.hpp
   models/Score.hpp
   models/PileType.hpp
   models/Ranking.hpp

   utils/ClosedInterval.hpp
   utils/IO.hpp
   utils/LimitedIntDialog.hpp
   utils/YesNoDialog.hpp
   utils/TextMenu.hpp
   utils/CommandReader.hpp
   utils/PermanentMediumPrototyper.hpp
   utils/PermanentMediumType.hpp
   utils/PermanentMediumReader.hpp
   utils/PermanentMediumWriter.hpp
   utils/TextFileReader.hpp
   utils/TextFileWriter.hpp

   views/KlondikeView.hpp
   views/StartView.hpp
   views/GameView.hpp
   views/ContinueView.hpp
   views/CardTableView.hpp
   views/CardView.hpp
   views/ViewManager.hpp
   views/text/KlondikeTextView.hpp
   views/text/StartTextView.hpp
   views/text/GameTextView.hpp
   views/text/ContinueTextView.hpp
   views/text/CardTableTextView.hpp
   views/text/CardTextViewManager.hpp
   views/text/CardTextView.hpp
   views/text/FrenchCardTextView.hpp
   views/text/SpanishCardTextView.hpp
   views/text/CommandInterpreter.hpp
)

set(SOURCE_FILES
   main.cpp
   Klondike.cpp

   configuration/KlondikeConfiguration.cpp
   configuration/DeckType.cpp

   controllers/FacadeCard.cpp
   controllers/Logic.cpp
   controllers/Controller.cpp
   controllers/StartController.cpp
   controllers/GameController.cpp
   controllers/ContinueController.cpp
   controllers/CardTableController.cpp
   controllers/CardCommand.cpp
   controllers/DrawCardCommand.cpp
   controllers/MoveCommand.cpp
   controllers/LeaveCommand.cpp
   controllers/ModifyHistoryCommand.cpp
   controllers/MoveController.cpp
   controllers/MovementHistory.cpp
   controllers/CommandManager.cpp

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
   models/DeckManager.cpp
   models/Score.cpp
   models/Ranking.cpp

   utils/ClosedInterval.cpp
   utils/IO.cpp
   utils/LimitedIntDialog.cpp
   utils/YesNoDialog.cpp
   utils/TextMenu.cpp
   utils/CommandReader.cpp
   utils/PermanentMediumPrototyper.cpp
   utils/TextFileReader.cpp
   utils/TextFileWriter.cpp

   views/ViewManager.cpp
   views/text/KlondikeTextView.cpp
   views/text/StartTextView.cpp
   views/text/GameTextView.cpp
   views/text/ContinueTextView.cpp
   views/text/CardTableTextView.cpp
   views/text/CardTextViewManager.cpp
   views/text/CardTextView.cpp
   views/text/FrenchCardTextView.cpp
   views/text/SpanishCardTextView.cpp
   views/text/CommandInterpreter.cpp
)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -g2")

include(cppcheck.cmake)

add_executable(klondike ${HEADER_FILES} ${SOURCE_FILES})
