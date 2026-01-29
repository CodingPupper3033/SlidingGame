//
// Created by codin on 1/25/26.
//

#ifndef SLIDINGGAME_SLIDINGGAME_H
#define SLIDINGGAME_SLIDINGGAME_H

#include "Board.h"

namespace SlidingGame::Core
{

    // SlidingGame class
    class SlidingGame
    {
    public:
        enum class Direction
        {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        /**
         * Sets up a sliding game with given size (width and height are equal)
         * @param size size of the board (width and height)
         */
        explicit SlidingGame(const Index size): SlidingGame(size, size) {}
        /**
         * Sets up a sliding game with given width and height
         * @param width width of the board
         * @param height height of the board
         */
        SlidingGame(Index width, Index height);

        /* Getters */
        [[nodiscard]] auto getWidth() const -> Index { return board.getWidth(); }
        [[nodiscard]] auto getHeight() const -> Index { return board.getHeight(); }
        [[nodiscard]] auto getMoves() const -> Index { return moves; }

        /**
         * Gets the cell at the given position.
         * @param x The x coordinate.
         * @param y The y coordinate.
         * @return A reference to the cell at the given position.
         */
        [[nodiscard]] auto at(Coord x, Coord y) const -> const Cell&;

        /**
         * Gets a row of cells at the given y coordinate.
         * @param y The y coordinate.
         * @return A vector of pointers to the cells in the row.
         */
        [[nodiscard]] auto getRow(Coord y) const -> std::vector<const Cell*>;

        /**
         * Offsets the given coordinates in the specified direction by the given offset.
         * @param x The x coordinate.
         * @param y The y coordinate.
         * @param direction The direction to offset.
         * @param offset The amount to offset.
         * @return A pair of the new x and y coordinates.
         */
        [[nodiscard]] static auto offsetCoord(Coord x, Coord y, Direction direction, Coord offset) -> std::pair<Coord, Coord>;

        /* Methods */
        auto slide(Coord x, Coord y, Direction direction) -> bool;

    private:
        Board board;

        Coord emptyX;
        Coord emptyY;

        Index moves = 0;
    };
}


#endif //SLIDINGGAME_SLIDINGGAME_H