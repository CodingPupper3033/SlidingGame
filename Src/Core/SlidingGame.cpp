//
// Created by codin on 1/25/26.
//

#include "Core/SlidingGame.h"
#include "Core/Board.hpp"
#include "Core/Cell/EmptyCell.hpp"
#include "Core/Cell/NumberCell.hpp"

SlidingGame::Core::SlidingGame::SlidingGame(size_t width, size_t height) : board(width, height)
{
    // Fill the board with number cells
    for (size_t i = 0; i < width * height - 1; i++) {
        const size_t x = i % width;
        const size_t y = i / width;
        board.setCell(x, y, std::unique_ptr<Cell>(new NumberCell(static_cast<int>(i + 1))));
    }

    // Set the last cell as the empty cell
    board.setCell(width - 1, height - 1, std::unique_ptr<Cell>(new EmptyCell()));
    emptyX = width - 1;
    emptyY = height - 1;
}

auto SlidingGame::Core::SlidingGame::at(size_t x, size_t y) const -> const Cell &
{
    return board.at(x, y);
}
