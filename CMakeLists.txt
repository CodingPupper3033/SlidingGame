cmake_minimum_required(VERSION 4.1)
project(SlidingGame)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------
# Dependencies
# ------------
include(FetchContent)

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(catch2)

# ---------------
# Project modules
# ---------------
add_subdirectory( Src/Core )
add_subdirectory( Src/CLI )
add_subdirectory( Tests )
