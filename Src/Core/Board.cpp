//
// Created by codin on 1/15/26.
//



#include "../../Inc/SlidingGame/Core/Board.hpp"

SlidingGame::Core::Board::Board(const size_t width, const size_t height)
    : m_width(width)
    , m_height(height)
{
    m_cells = std::vector<std::unique_ptr<Cell>>(width * height);
}

auto SlidingGame::Core::Board::at(const Cord x, const Cord y) const -> const Cell &
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

auto SlidingGame::Core::Board::getRow(const Cord y) const -> std::vector<const Cell*>
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

void SlidingGame::Core::Board::setCell(const std::size_t x, const std::size_t y, std::unique_ptr<Cell> cell)
{
    ensureInBounds(x,y);

    // Set the cell
    m_cells[index(x,y)] = std::move(cell);
}

void SlidingGame::Core::Board::swap(const std::size_t x1, const std::size_t y1, const std::size_t x2, const std::size_t y2)
{
    ensureInBounds(x1,y1);
    ensureInBounds(x2,y2);

    // Swap the cells
    std::swap(m_cells[index(x1,y1)], m_cells[index(x2,y2)]);
}

bool SlidingGame::Core::Board::isInBounds(const std::size_t x, const std::size_t y) const
{
    // Check if the position is valid
    return x < m_width &&
           y < m_height;
}

void SlidingGame::Core::Board::ensureInBounds(size_t x, size_t y) const
{
    if (!isInBounds(x, y)) {
        throw std::out_of_range("Cell position out of bounds");
    }
}
