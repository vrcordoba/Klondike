
cmake_minimum_required(VERSION 2.8.11)
project(Klondike)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/configuration)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/controllers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/controllers/commands)
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
   controllers/GameControllerPrototyper.hpp
   controllers/GameController.hpp
   controllers/GameControllerVisitor.hpp
   controllers/ManualGameController.hpp
   controllers/AutomaticGameController.hpp
   controllers/ContinueController.hpp
   controllers/CardTableController.hpp
   controllers/SaveController.hpp
   controllers/LoadController.hpp
   controllers/commands/CommandType.hpp
   controllers/commands/Command.hpp
   controllers/commands/ValidationCommand.hpp
   controllers/commands/CardCommand.hpp
   controllers/commands/CardCommandDiscriminator.hpp
   controllers/commands/CardCommandVisitor.hpp
   controllers/commands/DrawCardCommand.hpp
   controllers/commands/MoveCommand.hpp
   controllers/commands/LeaveCommand.hpp
   controllers/commands/SaveCommand.hpp
   controllers/commands/ModifyHistoryCommand.hpp
   controllers/commands/MovementHistory.hpp
   controllers/commands/CommandPrototyper.hpp

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
   models/DeckPrototyper.hpp
   models/Score.hpp
   models/PileType.hpp
   models/Ranking.hpp

   utils/ClosedInterval.hpp
   utils/IO.hpp
   utils/LimitedIntDialog.hpp
   utils/YesNoDialog.hpp
   utils/NumericTextMenu.hpp
   utils/PermanentMedium.hpp
   utils/PermanentMediumPrototyper.hpp
   utils/PermanentMediumReader.hpp
   utils/PermanentMediumWriter.hpp
   utils/PlainTextFileReader.hpp
   utils/PlainTextFileWriter.hpp

   views/KlondikeView.hpp
   views/StartView.hpp
   views/GameView.hpp
   views/ContinueView.hpp
   views/CardTableView.hpp
   views/CardView.hpp
   views/ViewPrototyper.hpp
   views/SaveView.hpp
   views/LoadView.hpp
   views/text/KlondikeTextView.hpp
   views/text/StartTextView.hpp
   views/text/GameTextView.hpp
   views/text/ContinueTextView.hpp
   views/text/CardTableTextView.hpp
   views/text/CardTextViewPrototyper.hpp
   views/text/CardTextView.hpp
   views/text/FrenchCardTextView.hpp
   views/text/SpanishCardTextView.hpp
   views/text/CommandInterpreter.hpp
   views/text/SaveTextView.hpp
   views/text/LoadTextView.hpp
   views/text/CommandTextMenu.hpp
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
   controllers/GameControllerPrototyper.cpp
   controllers/GameController.cpp
   controllers/ManualGameController.cpp
   controllers/AutomaticGameController.cpp
   controllers/ContinueController.cpp
   controllers/CardTableController.cpp
   controllers/SaveController.cpp
   controllers/LoadController.cpp
   controllers/commands/Command.cpp
   controllers/commands/ValidationCommand.cpp
   controllers/commands/CardCommand.cpp
   controllers/commands/CardCommandDiscriminator.cpp
   controllers/commands/DrawCardCommand.cpp
   controllers/commands/MoveCommand.cpp
   controllers/commands/LeaveCommand.cpp
   controllers/commands/SaveCommand.cpp
   controllers/commands/ModifyHistoryCommand.cpp
   controllers/commands/MovementHistory.cpp
   controllers/commands/CommandPrototyper.cpp

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
   models/DeckPrototyper.cpp
   models/Score.cpp
   models/Ranking.cpp

   utils/ClosedInterval.cpp
   utils/IO.cpp
   utils/LimitedIntDialog.cpp
   utils/YesNoDialog.cpp
   utils/NumericTextMenu.cpp
   utils/PermanentMediumPrototyper.cpp
   utils/PlainTextFileReader.cpp
   utils/PlainTextFileWriter.cpp

   views/ViewPrototyper.cpp
   views/text/KlondikeTextView.cpp
   views/text/StartTextView.cpp
   views/text/GameTextView.cpp
   views/text/ContinueTextView.cpp
   views/text/CardTableTextView.cpp
   views/text/CardTextViewPrototyper.cpp
   views/text/CardTextView.cpp
   views/text/FrenchCardTextView.cpp
   views/text/SpanishCardTextView.cpp
   views/text/CommandInterpreter.cpp
   views/text/SaveTextView.cpp
   views/text/LoadTextView.cpp
    views/text/CommandTextMenu.cpp
)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -g2")

include(cppcheck.cmake)

add_executable(klondike ${HEADER_FILES} ${SOURCE_FILES})
