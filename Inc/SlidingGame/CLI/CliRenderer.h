//
// Created by codin on 1/25/26.
//

#ifndef SLIDINGGAME_CLIRENDERER_H
#define SLIDINGGAME_CLIRENDERER_H
#include "Core/SlidingGame.h"

namespace SlidingGame::CLI
{
    class CliRenderer
    {
    public:
        CliRenderer() = default;

        static void renderBoard(const Core::SlidingGame& game);
    };
}



#endif //SLIDINGGAME_CLIRENDERER_H