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
        [[nodiscard]] auto get_width() const -> unsigned int { return m_width; }
        [[nodiscard]] auto get_height() const -> unsigned int { return m_height; }

        [[nodiscard]] auto at(int x, int y) const -> const Cell&;

        /* Setters */
        void set_cell(int x, int y, std::unique_ptr<Cell> cell);

        /* Methods */
        void swap(int x1, int y1, int x2, int y2);

        ~Board() = default;
    private:
        std::size_t m_width{};
        std::size_t m_height{};
        std::vector<std::unique_ptr<Cell>> m_cells;

        /* Index & Position */
        [[nodiscard]] bool is_valid_position(int x, int y) const;
        void ensure_valid_position(int x, int y) const;
        [[nodiscard]] std::size_t index(const int x, const int y) const { return y * m_width + x; }
    };
}


#endif //SLIDINGGAME_BOARD_H