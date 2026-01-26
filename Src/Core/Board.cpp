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

auto SlidingGame::Core::Board::at(const std::size_t x, const std::size_t y) const -> const Cell &
{
    ensure_valid_position(x,y);

    // Get the cell
    const auto &ptr = m_cells[y * m_width + x];

    // Check if the cell is null
    if (ptr == nullptr) {
        throw std::runtime_error("Cell at position is null");
    }

    // Return the cell
    return *ptr;
}

void SlidingGame::Core::Board::set_cell(const std::size_t x, const std::size_t y, std::unique_ptr<Cell> cell)
{
    ensure_valid_position(x,y);

    // Set the cell
    m_cells[index(x,y)] = std::move(cell);
}

void SlidingGame::Core::Board::swap(const std::size_t x1, const std::size_t y1, const std::size_t x2, const std::size_t y2)
{
    ensure_valid_position(x1,y1);
    ensure_valid_position(x2,y2);

    // Swap the cells
    std::swap(m_cells[index(x1,y1)], m_cells[index(x2,y2)]);
}

bool SlidingGame::Core::Board::is_valid_position(std::size_t x, std::size_t y) const
{
    // Check if the position is valid
    return static_cast<size_t>(x) < static_cast<size_t>(m_width) &&
           static_cast<size_t>(y) < static_cast<size_t>(m_height);
}

void SlidingGame::Core::Board::ensure_valid_position(size_t x, size_t y) const
{
    if (!is_valid_position(x, y)) {
        throw std::out_of_range("Cell position out of bounds");
    }
}
