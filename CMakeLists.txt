cmake_minimum_required(VERSION 3.21)
project(SlidingGame LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------
# Project modules
# ---------------
add_subdirectory( Src/Core )
add_subdirectory( Src/Utils )
add_subdirectory( Src/CLI )
add_subdirectory( Src/GUI )
# ---------------
# Tests
# ---------------
add_subdirectory( Tests )
