//
// Created by codin on 1/25/26.
//

#include <iostream>

#include "CLI/CliRenderer.h"

using namespace SlidingGame;

int main()
{
    // Create a sliding game instance
    auto game = Core::SlidingGame(4);

    // Create a CLI renderer
    const auto renderer = CLI::CliRenderer({ CLI::Theme::DoubleLineBoxDrawing, CLI::Theme::TextAlign::CENTER, "", 1 });

    // Print the initial state of the game board
    renderer.renderBoard(game);

    while (true) {
        // Get user input for sliding a cell
        char input;
        std::cout << "Enter direction to slide (w/a/s/d) or 'q' to quit: ";
        std::cin >> input;

        if (input == 'q') {
            break; // Exit the loop if user wants to quit
        }

        bool moved = false;
        auto [emptyX, emptyY] = game.getEmptyCellPosition();
        switch (input) {
            case 'w':
                moved = game.slide(emptyX, emptyY + 1, Core::SlidingGame::Direction::UP);
                break;
            case 's':
                moved = game.slide(emptyX, emptyY - 1, Core::SlidingGame::Direction::DOWN);
                break;
            case 'a':
                moved = game.slide(emptyX + 1, emptyY, Core::SlidingGame::Direction::LEFT);
                break;
            case 'd':
                moved = game.slide(emptyX - 1, emptyY, Core::SlidingGame::Direction::RIGHT);
                break;
            default:
                std::cout << "Invalid input. Please use w/a/s/d to slide or q to quit." << std::endl;
                continue;
        }
        if (moved) {
            renderer.renderBoard(game);
        } else {
            std::cout << "Move not possible in that direction." << std::endl;
        }

    }
    
    return 0;
}