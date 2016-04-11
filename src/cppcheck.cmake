# additional target to perform cppcheck run, requires cppcheck

file(GLOB_RECURSE ALL_SOURCE_FILES
   controllers/local/*.cpp
   controllers/local/*.hpp
   controllers/*.cpp
   controllers/*.hpp
   Klondike.cpp
   Klondike.hpp
   main.cpp
   models/*.cpp
   models/*.hpp
   utils/*.cpp
   utils/*.hpp
   views/text/*.cpp
   views/text/*.hpp
   views/*.cpp
   views/*.hpp
)

add_custom_target(
   cppcheck
   COMMAND /usr/bin/cppcheck
   --enable=all
   --std=c++11
   --verbose
   --quiet
   ${ALL_SOURCE_FILES}
)

