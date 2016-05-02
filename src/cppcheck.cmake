# additional target to perform cppcheck run, requires cppcheck

file(GLOB_RECURSE ALL_SOURCE_FILES
   configuration/*.cpp
   controllers/commands/*.cpp
   controllers/*.cpp
   Klondike.cpp
   main.cpp
   models/*.cpp
   utils/*.cpp
   views/text/*.cpp
   views/*.cpp
)

add_custom_target(
   cppcheck
   COMMAND /usr/bin/cppcheck
   --enable=all
   --std=c++11
   --verbose
   --quiet
   --suppress=missingIncludeSystem
   -I configuration -I controllers/commands
   -I controllers -I models -I utils -I views/text
   -I views ${ALL_SOURCE_FILES}
)

