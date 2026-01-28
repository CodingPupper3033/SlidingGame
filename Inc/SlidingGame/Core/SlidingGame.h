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

        explicit SlidingGame(const Index size): SlidingGame(size, size) {}
        SlidingGame(Index width, Index height);

        /* Getters */
        [[nodiscard]] auto getWidth() const -> size_t { return board.getWidth(); }
        [[nodiscard]] auto getHeight() const -> size_t { return board.getHeight(); }
        [[nodiscard]] auto getMoves() const -> int { return moves; }

        [[nodiscard]] auto at(size_t x, size_t y) const -> const Cell&;
        [[nodiscard]] auto getRow(size_t y) const -> std::vector<const Cell*>;

        /* Methods */
        auto slide(size_t x, size_t y, Direction direction) -> bool;

    private:
        Board board;

        size_t emptyX;
        size_t emptyY;

        int moves = 0;
    };
}


#endif //SLIDINGGAME_SLIDINGGAME_H