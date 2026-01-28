//
// Created by codin on 1/25/26.
//

#ifndef SLIDINGGAME_SLIDINGGAME_H
#define SLIDINGGAME_SLIDINGGAME_H

#include "Board.hpp"

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

        explicit SlidingGame(const size_t size): SlidingGame(size, size) {}
        SlidingGame(size_t width, size_t height);

        /* Getters */
        [[nodiscard]] auto getWidth() const -> size_t { return board.getWidth(); }
        [[nodiscard]] auto getHeight() const -> size_t { return board.getHeight(); }
        [[nodiscard]] auto getMoves() const -> int { return moves; }

        [[nodiscard]] auto at(size_t x, size_t y) const -> const Cell&;
        [[nodiscard]] auto getRow(size_t y) const -> std::vector<const Cell*>;

        /* Methods */
        /**
         * Attempts to slide the tile at position (x, y) in the specified direction.
         * The move succeeds only if the empty cell is adjacent in that direction.
         * @param x x coordinate of the tile to slide
         * @param y y coordinate of the tile to slide
         * @param direction direction to slide the tile (UP, DOWN, LEFT, RIGHT)
         * @return true if the slide was successful, false otherwise
         */
        auto slide(size_t x, size_t y, Direction direction) -> bool;

    private:
        Board board;

        size_t emptyX;
        size_t emptyY;

        int moves = 0;
    };
}


#endif //SLIDINGGAME_SLIDINGGAME_H