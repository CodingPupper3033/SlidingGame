#include <iostream>

#include "Core/Board.hpp"
#include "Core/SlidingGame.h"
#include "Core/Cell/NumberCell.hpp"
#include "Inc/SlidingGame/Core/Cell/Cell.hpp"
#include "Inc/SlidingGame/Core/Cell/EmptyCell.hpp"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon Src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    auto game = SlidingGame::Core::SlidingGame(4);


    // Print the initial state of the game board
    for (size_t y = 0; y < 4; y++) {
        for (size_t x = 0; x < 4; x++) {
            const SlidingGame::Core::Cell& cell = game.at(x, y);

            printf("%s", cell.isEmpty() ? "." : std::to_string(dynamic_cast<const SlidingGame::Core::NumberCell&>(cell).getValue()).c_str());
            if (x < 4 - 1) {
                printf("\t");
            }
        }
        printf("\n");
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}