cmake_minimum_required (VERSION 3.0.2)
project (cursestest)
add_executable (cursestest
./Source/main.cpp)
find_package(Curses)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(FFmpeg REQUIRED
	COMPONENTS avformat)
find_package(Threads REQUIRED)
include_directories(SYSTEM ${ZLIB_INCLUDE_DIR})
include_directories(${FFMPEG_INCLUDE_DIRS})
target_link_libraries(cursestest Threads::Threads ${CURSES_LIBRARIES} ${FFMPEG_LIBRARIES})
