//
// Created by codin on 1/26/26.
//

#include "../../Inc/SlidingGame/Core/Board.h"
#include "../../Inc/SlidingGame/Core/Cell/Cell.h"
#include "catch2/catch_test_macros.hpp"
#include "Core/Cell/EmptyCell.h"
#include "Core/Cell/NumberCell.h"

TEST_CASE("EmptyCell: is empty", "[Cell][EmptyCell]")
{
    using namespace SlidingGame::Core;

    const EmptyCell emptyCell;

    REQUIRE(emptyCell.isEmpty());
}

TEST_CASE("NumberCell: is not empty and has correct value", "[Cell][NumberCell]")
{
    using namespace SlidingGame::Core;

    const NumberCell numberCell(5);

    REQUIRE_FALSE(numberCell.isEmpty());
    REQUIRE(numberCell.getValue() == 5);
}

TEST_CASE("Cell: are polymorphic", "[Cell][Polymorphism]")
{
    using namespace SlidingGame::Core;

    const std::unique_ptr<Cell> emptyCell = std::make_unique<EmptyCell>();
    const std::unique_ptr<Cell> numberCell = std::make_unique<NumberCell>(10);

    // EmptyCell
    REQUIRE(emptyCell->isEmpty());
    REQUIRE(emptyCell->getValue() == std::nullopt);

    // NumberCell
    REQUIRE_FALSE(numberCell->isEmpty());
    REQUIRE(numberCell->getValue() == 10);
}

TEST_CASE("NumberCell: with negative value", "[Cell][NumberCell][NegativeValue]")
{
    using namespace SlidingGame::Core;

    const NumberCell negativeNumberCell(-3);

    REQUIRE_FALSE(negativeNumberCell.isEmpty());
    REQUIRE(negativeNumberCell.getValue() == -3);
}

static_assert(std::is_abstract_v<SlidingGame::Core::Cell>, "Cell must remain an abstract class.");
TEST_CASE("Cell: can't be instantiated directly", "[Cell][Abstract]")
{
    SUCCEED("Cell is abstract and cannot be instantiated directly.");
}