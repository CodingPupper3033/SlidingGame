cmake_minimum_required(VERSION 4.1)
project(SlidingGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(SlidingGame main.cpp
        Src/Core/Cell/Cell.cpp
        Src/Core/Cell/EmptyCell.cpp
        Src/Core/Cell/NumberCell.cpp
        Inc/SlidingGame/Core/Board.hpp
        Src/Core/Board.cpp
        Src/Core/SlidingGame.cpp
        Inc/SlidingGame/Core/SlidingGame.h)

target_include_directories(SlidingGame PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc/SlidingGame)
