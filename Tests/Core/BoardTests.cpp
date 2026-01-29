//
// Created by codin on 1/26/26.
//

#include "catch2/catch_test_macros.hpp"
#include "Core/Board.h"
#include "Core/Cell/NumberCell.h"

TEST_CASE("Board: Cell Access and Manipulation", "[Board][Cell]")
{
    using namespace SlidingGame::Core;

    Board board(3, 3);

    // Set cells
    board.setCell(0, 0, std::make_unique<NumberCell>(1));
    board.setCell(1, 0, std::make_unique<NumberCell>(2));
    board.setCell(2, 0, std::make_unique<NumberCell>(3));

    // Get and verify cells
    REQUIRE(dynamic_cast<const NumberCell&>(board.at(0, 0)).getValue() == 1);
    REQUIRE(dynamic_cast<const NumberCell&>(board.at(1, 0)).getValue() == 2);
    REQUIRE(dynamic_cast<const NumberCell&>(board.at(2, 0)).getValue() == 3);
}

TEST_CASE("Board: Get Row of Cells", "[Board][Row]")
{
    using namespace SlidingGame::Core;

    Board board(3, 3);

    // Set cells in the first row
    board.setCell(0, 1, std::make_unique<NumberCell>(4));
    board.setCell(1, 1, std::make_unique<NumberCell>(5));
    board.setCell(2, 1, std::make_unique<NumberCell>(6));

    // Get the row and verify cells
    const auto row = board.getRow(1);
    REQUIRE(row.size() == 3);
    REQUIRE(dynamic_cast<const NumberCell&>(*row[0]).getValue() == 4);
    REQUIRE(dynamic_cast<const NumberCell&>(*row[1]).getValue() == 5);
    REQUIRE(dynamic_cast<const NumberCell&>(*row[2]).getValue() == 6);
}

TEST_CASE("Board: Out of Bounds Access", "[Board][Bounds]")
{
    using namespace SlidingGame::Core;

    Board board(2, 2);

    // Accessing out of bounds should throw an exception
    REQUIRE_THROWS_AS(board.at(-1, 0), std::out_of_range);
    REQUIRE_THROWS_AS(board.at(0, -1), std::out_of_range);
    REQUIRE_THROWS_AS(board.at(2, 0), std::out_of_range);
    REQUIRE_THROWS_AS(board.at(0, 2), std::out_of_range);
}

TEST_CASE("Board: isInBounds Method", "[Board][Bounds]")
{
    using namespace SlidingGame::Core;

    Board board(3, 3);

    REQUIRE(board.isInBounds(0, 0));
    REQUIRE(board.isInBounds(2, 2));
    REQUIRE_FALSE(board.isInBounds(-1, 0));
    REQUIRE_FALSE(board.isInBounds(0, -1));
    REQUIRE_FALSE(board.isInBounds(3, 0));
    REQUIRE_FALSE(board.isInBounds(0, 3));
}