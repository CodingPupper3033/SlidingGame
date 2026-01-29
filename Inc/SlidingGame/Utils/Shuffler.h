//
// Created by codin on 1/28/26.
//

#ifndef SLIDINGGAME_SHUFFLER_H
#define SLIDINGGAME_SHUFFLER_H

#include "Core/Board.h"

namespace SlidingGame::Core
{
    class SlidingGame;
}

namespace SlidingGame::Utils
{
    class Shuffler
    {
    public:
        static auto shuffleSlidingGame(Core::SlidingGame &sliding_game, Core::Index shuffleMoves) -> void;
    };
}

#endif //SLIDINGGAME_SHUFFLER_H