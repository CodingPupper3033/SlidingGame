//
// Created by codin on 1/15/26.
//



#include "../../Inc/SlidingGame/Core/Board.h"

SlidingGame::Core::Board::Board(const size_t width, const size_t height)
    : m_width(width)
    , m_height(height)
{
    m_cells = std::vector<std::unique_ptr<Cell>>(width * height);
}

auto SlidingGame::Core::Board::at(const Coord x, const Coord y) const -> const Cell &
{
    ensureInBounds(x,y);

    // Get the cell
    const auto &ptr = m_cells[y * m_width + x];

    // Check if the cell is null
    if (ptr == nullptr) {
        throw std::runtime_error("Cell at position is null");
    }

    // Return the cell
    return *ptr;
}

auto SlidingGame::Core::Board::getRow(const Coord y) const -> std::vector<const Cell*>
{
    ensureInBounds(0,y);

    std::vector<const Cell*> row;
    row.reserve(m_width);

    for (std::size_t x = 0; x < m_width; ++x) {
        const auto &ptr = m_cells[index(x,y)];
        if (ptr == nullptr) {
            throw std::runtime_error("Cell at position is null");
        }
        row.push_back(ptr.get());
    }

    return row;
}

void SlidingGame::Core::Board::setCell(const Coord x, const Coord y, std::unique_ptr<Cell> cell)
{
    ensureInBounds(x,y);

    // Set the cell
    m_cells[index(x,y)] = std::move(cell);
}

void SlidingGame::Core::Board::swap(const Coord x1, const Coord y1, const Coord x2, const Coord y2)
{
    ensureInBounds(x1,y1);
    ensureInBounds(x2,y2);

    // Swap the cells
    std::swap(m_cells[index(x1,y1)], m_cells[index(x2,y2)]);
}

bool SlidingGame::Core::Board::isInBounds(const Coord x, const Coord y) const
{
    // Check for negative values
    if (x < 0 || y < 0) {
        return false;
    }

    // Check for out of bounds
    return x < m_width &&
           y < m_height;
}

void SlidingGame::Core::Board::ensureInBounds(const Coord x, const Coord y) const
{
    if (!isInBounds(x,y)) {
        throw std::out_of_range("Cell position out of bounds");
    }
}
