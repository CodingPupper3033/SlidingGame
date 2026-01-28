//
// Created by codin on 1/25/26.
//

#include "Core/SlidingGame.h"
#include "Core/Board.h"
#include "Core/Cell/EmptyCell.h"
#include "Core/Cell/NumberCell.h"

SlidingGame::Core::SlidingGame::SlidingGame(const size_t width, const size_t height) : board(width, height)
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

auto SlidingGame::Core::SlidingGame::at(const size_t x, const size_t y) const -> const Cell &
{
    return board.at(x, y);
}

auto SlidingGame::Core::SlidingGame::getRow(const size_t y) const -> std::vector<const Cell *>
{
    return board.getRow(y);
}
