//
// Created by codin on 1/25/26.
//

#ifndef SLIDINGGAME_CLIRENDERER_H
#define SLIDINGGAME_CLIRENDERER_H

#include "Core/SlidingGame.h"
#include "Themes.h"

namespace SlidingGame::CLI
{
    class CliRenderer
    {
    public:
        explicit CliRenderer(
            Theme::Theme theme = { Theme::UnicodeBoxDrawing, Theme::TextAlign::CENTER, " ", 1 },
            size_t cell_width = 0
            );

        void renderBoard(const Core::SlidingGame& game) const;

        [[nodiscard]] auto drawBoard(const Core::SlidingGame &game) const -> std::string;

    private:
        enum class SeparatorType
        {
            TOP,
            MIDDLE,
            BOTTOM
        };

        [[nodiscard]] auto drawRow(const std::vector<const Core::Cell *> &row, size_t cell_width) const -> std::string;
        [[nodiscard]] auto drawSeparatorRow(size_t num_cells, size_t cell_width, SeparatorType type) const -> std::string;
        [[nodiscard]] auto drawCell(const Core::Cell &cell, size_t cell_width) const -> std::string;

        Theme::Theme m_theme;
        unsigned int m_cell_width;
    };
}



#endif //SLIDINGGAME_CLIRENDERER_H