add_library( SlidingGameCore STATIC
        Cell/Cell.cpp
        Cell/EmptyCell.cpp
        Cell/NumberCell.cpp
        Board.cpp
        SlidingGame.cpp
)

target_include_directories( SlidingGameCore PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Inc/SlidingGame
)