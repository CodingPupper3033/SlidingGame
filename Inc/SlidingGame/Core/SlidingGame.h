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

        SlidingGame(size_t width, size_t height);
        auto slide(int x, int y, Direction direction) -> void;

    private:
        Board board;
    };
}


#endif //SLIDINGGAME_SLIDINGGAME_H