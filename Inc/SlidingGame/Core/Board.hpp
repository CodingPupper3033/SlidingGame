//
// Created by codin on 1/15/26.
//

#ifndef SLIDINGGAME_BOARD_H
#define SLIDINGGAME_BOARD_H
#include <memory>
#include <vector>

#include "Cell/Cell.hpp"

namespace SlidingGame::Core
{
    class Board
    {
    public:
        Board(std::size_t width, std::size_t height);

        /* Getters */
        [[nodiscard]] auto get_width() const -> std::size_t { return m_width; }
        [[nodiscard]] auto get_height() const -> std::size_t { return m_height; }

        [[nodiscard]] auto at(std::size_t x, std::size_t y) const -> const Cell&;

        /* Setters */
        void set_cell(std::size_t x, std::size_t y, std::unique_ptr<Cell> cell);

        /* Methods */
        void swap(std::size_t x1, std::size_t y1, std::size_t x2, std::size_t y2);

        ~Board() = default;
    private:
        std::size_t m_width{};
        std::size_t m_height{};
        std::vector<std::unique_ptr<Cell>> m_cells;

        /* Index & Position */
        [[nodiscard]] bool is_valid_position(std::size_t x, std::size_t y) const;
        void ensure_valid_position(std::size_t x, std::size_t y) const;
        [[nodiscard]] std::size_t index(const std::size_t x, const std::size_t y) const { return y * m_width + x; }
    };
}


#endif //SLIDINGGAME_BOARD_H