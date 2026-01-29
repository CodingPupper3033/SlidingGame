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

TEST_CASE("SlidingGame: Initial Number Cell Positions", "[SlidingGame][Core]") {
    const SlidingGame::Core::SlidingGame game(3, 3);

    const auto& cell_0_0 = game.at(0, 0);
    REQUIRE(!cell_0_0.isEmpty());
    REQUIRE(cell_0_0.getValue() == 1);

    const auto& cell_1_0 = game.at(1, 0);
    REQUIRE(!cell_1_0.isEmpty());
    REQUIRE(cell_1_0.getValue() == 2);

    const auto& cell_2_0 = game.at(2, 0);
    REQUIRE(!cell_2_0.isEmpty());
    REQUIRE(cell_2_0.getValue() == 3);

    const auto& cell_0_1 = game.at(0, 1);
    REQUIRE(!cell_0_1.isEmpty());
    REQUIRE(cell_0_1.getValue() == 4);

    const auto& cell_1_1 = game.at(1, 1);
    REQUIRE(!cell_1_1.isEmpty());
    REQUIRE(cell_1_1.getValue() == 5);

    const auto& cell_2_1 = game.at(2, 1);
    REQUIRE(!cell_2_1.isEmpty());
    REQUIRE(cell_2_1.getValue() == 6);

    const auto& cell_0_2 = game.at(0, 2);
    REQUIRE(!cell_0_2.isEmpty());
    REQUIRE(cell_0_2.getValue() == 7);

    const auto& cell_1_2 = game.at(1, 2);
    REQUIRE(!cell_1_2.isEmpty());
    REQUIRE(cell_1_2.getValue() == 8);
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

TEST_CASE("SlidingGame: Get Row of Cells", "[SlidingGame][Core]") {
    SlidingGame::Core::SlidingGame game(4, 4);

    const auto row = game.getRow(1);
    REQUIRE(row.size() == 4);
    REQUIRE(row[0]->getValue() == 5);
    REQUIRE(row[1]->getValue() == 6);
    REQUIRE(row[2]->getValue() == 7);
    REQUIRE(row[3]->getValue() == 8);
}