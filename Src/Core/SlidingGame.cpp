//
// Created by codin on 1/25/26.
//

#include "Core/SlidingGame.h"
#include "Core/Board.hpp"
#include "Core/Cell/EmptyCell.hpp"
#include "Core/Cell/NumberCell.hpp"

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

auto SlidingGame::Core::SlidingGame::slide(const size_t x, const size_t y, const Direction direction) -> bool
{
    // Check if the cell at (x, y) is adjacent to the empty cell
    size_t targetX = x;
    size_t targetY = y;
    
    switch (direction) {
        case Direction::UP:
            if (y == 0) return false;
            targetY = y - 1;
            break;
        case Direction::DOWN:
            if (y >= getHeight() - 1) return false;
            targetY = y + 1;
            break;
        case Direction::LEFT:
            if (x == 0) return false;
            targetX = x - 1;
            break;
        case Direction::RIGHT:
            if (x >= getWidth() - 1) return false;
            targetX = x + 1;
            break;
    }
    
    // Check if the target cell is the empty cell
    if (targetX != emptyX || targetY != emptyY) {
        return false;
    }
    
    // Swap the cells
    board.swap(x, y, emptyX, emptyY);
    emptyX = x;
    emptyY = y;
    moves++;
    
    return true;
}
