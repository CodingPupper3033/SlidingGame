//
// Created by codin on 1/25/26.
//

#include "CLI/CliRenderer.h"

using namespace SlidingGame;

int main()
{
    // Create a sliding game instance
    const auto game = Core::SlidingGame(4);

    // Create a CLI renderer
    const auto renderer = CLI::CliRenderer({ CLI::Theme::DoubleLineBoxDrawing, CLI::Theme::TextAlign::CENTER, "", 1 });

    // Print the initial state of the game board
    renderer.renderBoard(game);

    return 0;
}
