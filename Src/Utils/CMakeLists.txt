add_library( SlidingGameUtils
        Shuffler.cpp
)

target_include_directories( SlidingGameUtils PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Inc/SlidingGame
)