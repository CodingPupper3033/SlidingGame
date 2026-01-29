//
// Created by codin on 1/28/26.
//

#include "catch2/catch_test_macros.hpp"
#include "Core/SlidingGame.h"

TEST_CASE("SlidingGame: Get Width and Height", "[SlidingGame][Core]") {
    const SlidingGame::Core::SlidingGame game(4, 5);

    REQUIRE(game.getWidth() == 4);
    REQUIRE(game.getHeight() == 5);
}

TEST_CASE("SlidingGame: Initial Empty Cell Position", "[SlidingGame][Core]") {
    const SlidingGame::Core::SlidingGame game(3, 3);

    const auto& emptyCell = game.at(2, 2);
    REQUIRE(emptyCell.isEmpty());
}

TEST_CASE("SlidingGame: Slide Cell into Empty Space", "[SlidingGame][Core]") {
    SlidingGame::Core::SlidingGame game(3, 3);

    // Slide the cell at (2,1) down into the empty space at (2,2)
    bool moved = game.slide(2, 1, SlidingGame::Core::SlidingGame::Direction::DOWN);
    REQUIRE(moved);

    // Verify the new positions
    const auto& movedCell = game.at(2, 2);
    REQUIRE(!movedCell.isEmpty());
    REQUIRE(movedCell.getValue() == 6); // Original value at (2,1)

    const auto& newEmptyCell = game.at(2, 1);
    REQUIRE(newEmptyCell.isEmpty());
}

TEST_CASE("SlidingGame: Invalid Slide Attempt", "[SlidingGame][Core]") {
    SlidingGame::Core::SlidingGame game(3, 3);

    // Attempt to slide a cell that is not adjacent to the empty space
    bool moved = game.slide(0, 0, SlidingGame::Core::SlidingGame::Direction::DOWN);
    REQUIRE(!moved); // Move should fail

    // Verify positions remain unchanged
    const auto& cell = game.at(0, 0);
    REQUIRE(!cell.isEmpty());
    REQUIRE(cell.getValue() == 1); // Original value at (0,0)

    const auto& emptyCell = game.at(2, 2);
    REQUIRE(emptyCell.isEmpty());
}