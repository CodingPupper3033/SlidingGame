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
        [[nodiscard]] auto getWidth() const -> Index { return board.getWidth(); }
        [[nodiscard]] auto getHeight() const -> Index { return board.getHeight(); }
        [[nodiscard]] auto getMoves() const -> Index { return moves; }

        [[nodiscard]] auto at(Coord x, Coord y) const -> const Cell&;
        [[nodiscard]] auto getRow(Coord y) const -> std::vector<const Cell*>;

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