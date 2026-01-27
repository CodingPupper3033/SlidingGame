//
// Created by codin on 1/26/26.
//

#ifndef SLIDINGGAME_THEMES_H
#define SLIDINGGAME_THEMES_H
#include <string_view>

namespace SlidingGame::CLI::Theme
{
    /** Box drawing characters for different themes. */
    struct BoxDrawing
    {
        std::string_view TOP_LEFT;
        std::string_view TOP_RIGHT;
        std::string_view BOTTOM_LEFT;
        std::string_view BOTTOM_RIGHT;
        std::string_view HORIZONTAL;
        std::string_view VERTICAL;
        std::string_view T_UP;
        std::string_view T_DOWN;
        std::string_view T_LEFT;
        std::string_view T_RIGHT;
        std::string_view CROSS;
    };

    inline constexpr BoxDrawing UnicodeBoxDrawing {
        .TOP_LEFT = "┌",
        .TOP_RIGHT = "┐",
        .BOTTOM_LEFT = "└",
        .BOTTOM_RIGHT = "┘",
        .HORIZONTAL = "─",
        .VERTICAL = "│",
        .T_UP = "┴",
        .T_DOWN = "┬",
        .T_LEFT = "┤",
        .T_RIGHT = "├",
        .CROSS = "┼"
    };

    inline constexpr BoxDrawing DoubleLineBoxDrawing {
        .TOP_LEFT = "╔",
        .TOP_RIGHT = "╗",
        .BOTTOM_LEFT = "╚",
        .BOTTOM_RIGHT = "╝",
        .HORIZONTAL = "═",
        .VERTICAL = "║",
        .T_UP = "╩",
        .T_DOWN = "╦",
        .T_LEFT = "╣",
        .T_RIGHT = "╠",
        .CROSS = "╬"
    };

    inline constexpr BoxDrawing ASCII {
        .TOP_LEFT = "+",
        .TOP_RIGHT = "+",
        .BOTTOM_LEFT = "+",
        .BOTTOM_RIGHT = "+",
        .HORIZONTAL = "-",
        .VERTICAL = "|",
        .T_UP = "+",
        .T_DOWN = "+",
        .T_LEFT = "+",
        .T_RIGHT = "+",
        .CROSS = "+"
    };

   enum class TextAlign
   {
         LEFT,
         CENTER,
         RIGHT
   };

    struct Theme
    {
        BoxDrawing boxDrawing;
        TextAlign textAlign;
        std::string_view emptyCellSymbol;
        unsigned int cellPadding;
    };
}

#endif //SLIDINGGAME_THEMES_H
