cmake_minimum_required (VERSION 3.0.2)
project (cursestest)
add_executable (cursestest
./Source/main.cpp)
find_package(Curses)
target_link_libraries(cursestest ${CURSES_LIBRARIES})
