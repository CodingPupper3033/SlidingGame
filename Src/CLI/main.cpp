//
// Created by codin on 1/25/26.
//

#include "CLI/CliRenderer.h"

using namespace SlidingGame;

int main()
{
    auto game = Core::SlidingGame(4);

    // Print the initial state of the game board
    CLI::CliRenderer::renderBoard(game);

    return 0;
}
