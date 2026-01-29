//
// Created by codin on 1/28/26.
//

#include "../../Inc/SlidingGame/Utils/Shuffler.h"

#include <array>
#include <ctime>

#include "Core/SlidingGame.h"


auto SlidingGame::Utils::Shuffler::shuffleSlidingGame(Core::SlidingGame &sliding_game, const Core::Index shuffleMoves) -> void
{
    using Direction = Core::SlidingGame::Direction;

    constexpr auto directions = std::array<Direction, 4>{
        Direction::UP,
        Direction::DOWN,
        Direction::LEFT,
        Direction::RIGHT
    };

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (sliding_game.getMoves() < shuffleMoves) {
        // Randomly select a direction
        const auto randomIndex = std::rand() % directions.size();
        const auto direction = directions[randomIndex];

        // Get the current empty cell position
        const auto [emptyX, emptyY] = sliding_game.getEmptyCellPosition();

        // Determine the cell to slide based on the direction
        Core::Index slideX = emptyX;
        Core::Index slideY = emptyY;

        switch (direction) {
            case Direction::UP:
                slideY += 1;
                break;
            case Direction::DOWN:
                slideY -= 1;
                break;
            case Direction::LEFT:
                slideX += 1;
                break;
            case Direction::RIGHT:
                slideX -= 1;
                break;
        }

        // Attempt to slide the cell into the empty space
        sliding_game.slide(slideX, slideY, direction);
    }

    // Reset move count after shuffling
    sliding_game.setMoves(0);
}
