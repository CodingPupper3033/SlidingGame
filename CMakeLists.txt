cmake_minimum_required(VERSION 4.1)
project(SlidingGame)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include subdirectories
add_subdirectory( Src/Core )
add_subdirectory( Src/CLI )
