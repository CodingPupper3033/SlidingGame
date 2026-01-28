//
// Created by codin on 1/26/26.
//

#include "catch2/catch_test_macros.hpp"
#include "Core/Board.h"
#include "Core/Cell/NumberCell.h"

TEST_CASE("Board Cell Access and Manipulation", "[Board][Cell]")
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