cmake_minimum_required(VERSION 3.11.0)
project(chess VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare( 
   googletest
   GIT_REPOSITORY      https://github.com/google/googletest.git
   GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

set(API_FOLDER chess_API)
set(BOT_FOLDER bot_API)
set(API_SOURCES
   ${API_FOLDER}/board.h
   ${API_FOLDER}/pieces.h
)
set(BOT_SOURCES
   ${BOT_FOLDER}/bot.h
)

set(PROJECT_SOURCES ${API_SOURCES} ${BOT_SOURCES})

add_executable(chess main.cpp ${PROJECT_SOURCES} )
