//
// Created by codin on 1/15/26.
//

#ifndef SLIDINGGAME_BOARD_H
#define SLIDINGGAME_BOARD_H
#include <memory>
#include <vector>

#include "Cell/Cell.h"

namespace SlidingGame::Core
{
    using Coord = int;
    using Index = std::size_t;

    class Board
    {
    public:
        /**
         * Sets up a board with given width and height
         * @param width width of the board
         * @param height height of the board
         */
        Board(Index width, Index height);

        /* Getters */
        /**
         * Gets the width of the board
         * @return width of the board
         */
        [[nodiscard]] auto getWidth() const -> Index { return m_width; }

        /**
         * Gets the height of the board
         * @return height of the board
         */
        [[nodiscard]] auto getHeight() const -> Index { return m_height; }

        /**
         * Gets the cell at the given position
         * @param x x coordinate
         * @param y y coordinate
         * @return reference to the cell at the given position
         */
        [[nodiscard]] auto at(Coord x, Coord y) const -> const Cell&;

        /**
         * Gets a row of cells at the given y coordinate
         * @param y y coordinate
         * @return vector of pointers to the cells in the row
         */
        [[nodiscard]] auto getRow(Coord y) const -> std::vector<const Cell*>;

        /* Setters */
        void setCell(Coord x, Coord y, std::unique_ptr<Cell> cell);

        /* Methods */
        void swap(Coord x1, Coord y1, Coord x2, Coord y2);

        ~Board() = default;
    private:
        Index m_width{};
        Index m_height{};
        std::vector<std::unique_ptr<Cell>> m_cells;

        /* Index & Position */
        [[nodiscard]] bool isInBounds(Coord x, Coord y) const;
        void ensureInBounds(Coord x, Coord y) const;
        [[nodiscard]] Index index(const Coord x, const Coord y) const { return y * m_width + x; }
    };
}


#endif //SLIDINGGAME_BOARD_H