//
// Created by codin on 1/28/26.
//

#include "catch2/catch_test_macros.hpp"
#include "Core/SlidingGame.h"

TEST_CASE("SlidingGame initialization", "[SlidingGame]")
{
    using Game = SlidingGame::Core::SlidingGame;

    SECTION("3x3 board")
    {
        Game game(3, 3);
        
        REQUIRE(game.getWidth() == 3);
        REQUIRE(game.getHeight() == 3);
        REQUIRE(game.getMoves() == 0);
        
        // Check that the last cell is empty
        REQUIRE(game.at(2, 2).isEmpty());
        
        // Check that other cells have correct values
        REQUIRE(game.at(0, 0).getValue() == 1);
        REQUIRE(game.at(1, 0).getValue() == 2);
        REQUIRE(game.at(2, 0).getValue() == 3);
        REQUIRE(game.at(0, 1).getValue() == 4);
    }

    SECTION("4x4 board")
    {
        Game game(4);
        
        REQUIRE(game.getWidth() == 4);
        REQUIRE(game.getHeight() == 4);
        
        // Check that the last cell is empty
        REQUIRE(game.at(3, 3).isEmpty());
    }
}

TEST_CASE("SlidingGame slide method - valid moves", "[SlidingGame][slide]")
{
    using Game = SlidingGame::Core::SlidingGame;
    using Direction = SlidingGame::Core::SlidingGame::Direction;

    SECTION("Slide tile left into empty space")
    {
        Game game(3, 3);
        // Empty cell is at (2, 2)
        // Board: 1 2 3
        //        4 5 6
        //        7 8 [ ]
        
        bool result = game.slide(1, 2, Direction::RIGHT);
        
        REQUIRE(result == true);
        REQUIRE(game.getMoves() == 1);
        REQUIRE(game.at(1, 2).isEmpty());
        REQUIRE(game.at(2, 2).getValue() == 8);
    }

    SECTION("Slide tile up into empty space")
    {
        Game game(3, 3);
        // Empty cell is at (2, 2)
        
        bool result = game.slide(2, 1, Direction::DOWN);
        
        REQUIRE(result == true);
        REQUIRE(game.getMoves() == 1);
        REQUIRE(game.at(2, 1).isEmpty());
        REQUIRE(game.at(2, 2).getValue() == 6);
    }

    SECTION("Multiple moves")
    {
        Game game(3, 3);
        // Empty cell is at (2, 2)
        
        // First move
        bool result1 = game.slide(2, 1, Direction::DOWN);
        REQUIRE(result1 == true);
        REQUIRE(game.getMoves() == 1);
        
        // Second move
        bool result2 = game.slide(1, 1, Direction::RIGHT);
        REQUIRE(result2 == true);
        REQUIRE(game.getMoves() == 2);
        
        // Third move
        bool result3 = game.slide(0, 1, Direction::RIGHT);
        REQUIRE(result3 == true);
        REQUIRE(game.getMoves() == 3);
    }
}

TEST_CASE("SlidingGame slide method - invalid moves", "[SlidingGame][slide]")
{
    using Game = SlidingGame::Core::SlidingGame;
    using Direction = SlidingGame::Core::SlidingGame::Direction;

    SECTION("Slide tile not adjacent to empty cell")
    {
        Game game(3, 3);
        // Empty cell is at (2, 2)
        
        bool result = game.slide(0, 0, Direction::RIGHT);
        
        REQUIRE(result == false);
        REQUIRE(game.getMoves() == 0);
    }

    SECTION("Slide in wrong direction")
    {
        Game game(3, 3);
        // Empty cell is at (2, 2)
        
        bool result = game.slide(1, 2, Direction::LEFT);
        
        REQUIRE(result == false);
        REQUIRE(game.getMoves() == 0);
    }

    SECTION("Slide empty cell itself")
    {
        Game game(3, 3);
        // Empty cell is at (2, 2)
        
        bool result = game.slide(2, 2, Direction::UP);
        
        REQUIRE(result == false);
        REQUIRE(game.getMoves() == 0);
    }
}

TEST_CASE("SlidingGame slide method - boundary conditions", "[SlidingGame][slide]")
{
    using Game = SlidingGame::Core::SlidingGame;
    using Direction = SlidingGame::Core::SlidingGame::Direction;

    SECTION("Slide at top edge")
    {
        Game game(3, 3);
        // Empty cell is at (2, 2)
        
        bool result = game.slide(0, 0, Direction::UP);
        
        REQUIRE(result == false);
        REQUIRE(game.getMoves() == 0);
    }

    SECTION("Slide at left edge")
    {
        Game game(3, 3);
        // Empty cell is at (2, 2)
        
        bool result = game.slide(0, 0, Direction::LEFT);
        
        REQUIRE(result == false);
        REQUIRE(game.getMoves() == 0);
    }

    SECTION("Slide with out of bounds coordinates")
    {
        Game game(3, 3);
        
        bool result = game.slide(10, 10, Direction::UP);
        
        REQUIRE(result == false);
        REQUIRE(game.getMoves() == 0);
    }
}
