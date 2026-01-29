//
// Created by codin on 1/25/26.
//

#include "Core/SlidingGame.h"

#include <strings.h>

#include "Core/Board.h"
#include "Core/Cell/EmptyCell.h"
#include "Core/Cell/NumberCell.h"

SlidingGame::Core::SlidingGame::SlidingGame(const Index width, const Index height) : board(width, height)
{
    // Fill the board with number cells
    for (Coord y = 0; y < height; y++)
        for (Coord x = 0; x < width; x++) {
            const Index number = board.index(x, y) + 1;
            if (number == width * height)
                break;
            board.setCell(x, y, std::unique_ptr<Cell>(new NumberCell(static_cast<int>(number))));
        }

    // Set the last cell as the empty cell
    emptyX = static_cast<Coord>(width - 1);
    emptyY = static_cast<Coord>(height - 1);
    board.setCell(emptyX, emptyY, std::unique_ptr<Cell>(new EmptyCell()));
}

auto SlidingGame::Core::SlidingGame::at(const Coord x, const Coord y) const -> const Cell &
{
    return board.at(x, y);
}

auto SlidingGame::Core::SlidingGame::getRow(const Coord y) const -> std::vector<const Cell *>
{
    return board.getRow(y);
}

auto SlidingGame::Core::SlidingGame::offsetCoord(const Coord x, const Coord y, const Direction direction,
    const Coord offset) -> std::pair<Coord, Coord>
{
    switch (direction) {
    case Direction::UP:
        return { x, (y - offset) };
    case Direction::DOWN:
        return { x, (y + offset) };
    case Direction::LEFT:
        return { (x - offset), y };
    case Direction::RIGHT:
        return { (x + offset), y };
    default:
        return { x, y };
    }
}

auto SlidingGame::Core::SlidingGame::slide(const Coord x, const Coord y, const Direction direction) -> bool
{
    if (!board.isInBounds(x, y))
        return false; // Ensure the sliding cell is within bounds

    if (x == emptyX && y == emptyY)
        return false; // Cannot slide the empty cell

    auto x_curr = static_cast<Coord>(x);
    auto y_curr = static_cast<Coord>(y);
    while (true) {
        // Get the next coordinates in the specified direction
        const auto [nextX, nextY] = offsetCoord(x_curr, y_curr, direction, 1);

        // Check if the next coordinates are out of bounds
        if (!board.isInBounds(nextX, nextY))
            return false;

        // Check if the next cell is the empty cell
        if (nextX == emptyX && nextY == emptyY) {
            // Found the empty cell, exit to perform the slide
            break;
        }

        // Move to the next cell
        x_curr = nextX;
        y_curr = nextY;
    }

    // Perform the slide by swapping cells from the empty cell to the target cell
    Coord x_slide = emptyX;
    Coord y_slide = emptyY;
    while (x_slide != x || y_slide != y) {
        const auto [prevX, prevY] = offsetCoord(x_slide, y_slide, direction, -1);
        board.swap(x_slide, y_slide, prevX, prevY);
        x_slide = prevX;
        y_slide = prevY;
    }

    // Update the empty cell position
    emptyX = x;
    emptyY = y;

    // Increment move count
    moves++;

    return true;
}

auto SlidingGame::Core::SlidingGame::isSolved() const -> bool
{
    for (Coord y = 0; y < getHeight(); y++)
        for (Coord x = 0; x < getWidth(); x++) {
            const Index index = board.index(x, y);
            const Cell &cell = board.at(x, y);

            // Last cell should be empty
            if (index == getWidth() * getHeight() - 1) {
                if (!cell.isEmpty())
                    return false;
                continue;
            }

            // Check if the cell is a NumberCell with the correct value
            const auto *numberCell = dynamic_cast<const NumberCell *>(&cell);
            if (!numberCell || numberCell->getValue() != static_cast<int>(index + 1))
                return false;
        }
    return true;
}
