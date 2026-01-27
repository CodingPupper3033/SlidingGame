//
// Created by codin on 1/25/26.
//

#include "CLI/CliRenderer.h"

#include <iomanip>
#include <iostream>
#include <string>

using namespace SlidingGame::CLI;

CliRenderer::CliRenderer(Theme::Theme theme, const size_t cell_width): m_theme(theme), m_cell_width(cell_width)
{
    if (cell_width == 0) {
        m_cell_width = 0; // auto-adjust
    } else if (cell_width < theme.emptyCellSymbol.length()) { // validate cell width
        throw std::invalid_argument(
            "Cell width must be greater than or equal to the length of the empty cell symbol."
            );
    } else  {
       m_cell_width = cell_width;
    }
}

void CliRenderer::renderBoard(const Core::SlidingGame &game) const
{
    std::cout << drawBoard(game);
}

auto CliRenderer::drawBoard(const Core::SlidingGame &game) const -> std::string
{
    auto cell_width = this->m_cell_width;
    // Determine cell width if auto-adjust is enabled
    if (m_cell_width == 0) {
        // Auto-adjust cell width based on the largest number in the game
        const size_t maxNumber = game.getWidth() * game.getHeight() - 1;
        cell_width = std::to_string(maxNumber).length();
        if (cell_width < m_theme.emptyCellSymbol.length()) {
            cell_width = m_theme.emptyCellSymbol.length();
        }
    }

    // Draw each row of the board
    std::ostringstream boardStr;
    boardStr << drawSeparatorRow(game.getWidth(), cell_width, SeparatorType::TOP) << '\n';
    for (size_t y = 0; y < game.getHeight(); ++y) {
        const auto row = game.getRow(y);
        const auto rowStr = drawRow(row, cell_width);
        boardStr << rowStr << '\n';

        if (y < game.getHeight() - 1) {
            boardStr << drawSeparatorRow(game.getWidth(), cell_width, SeparatorType::MIDDLE) << '\n';
        }
    }
    boardStr << drawSeparatorRow(game.getWidth(), cell_width, SeparatorType::BOTTOM) << '\n';

    // Return the complete board string
    return boardStr.str();
}

auto CliRenderer::drawRow(const std::vector<const Core::Cell *> &row, const size_t cell_width) const -> std::string
{
    std::string rowStr;

    // Draw each cell in the row
    for (const auto* cell : row) {
        rowStr += m_theme.boxDrawing.VERTICAL;
        rowStr += drawCell(*cell, cell_width);
    }
    rowStr += m_theme.boxDrawing.VERTICAL; // End of row

    return rowStr;
}

auto CliRenderer::drawSeparatorRow(size_t num_cells, size_t cell_width, SeparatorType type) const -> std::string
{
    std::string separatorStr;

    // Determine the box drawing characters based on the separator type
    std::string_view left, middle, right;
    switch (type) {
        case SeparatorType::TOP:
            left = m_theme.boxDrawing.TOP_LEFT;
            middle = m_theme.boxDrawing.T_DOWN;
            right = m_theme.boxDrawing.TOP_RIGHT;
            break;
        case SeparatorType::MIDDLE:
            left = m_theme.boxDrawing.T_RIGHT;
            middle = m_theme.boxDrawing.CROSS;
            right = m_theme.boxDrawing.T_LEFT;
            break;
        case SeparatorType::BOTTOM:
            left = m_theme.boxDrawing.BOTTOM_LEFT;
            middle = m_theme.boxDrawing.T_UP;
            right = m_theme.boxDrawing.BOTTOM_RIGHT;
            break;
    }
    const std::string_view horizontal = m_theme.boxDrawing.HORIZONTAL;

    // Build the separator row string
    auto repeat = [](std::string_view glyph, size_t count) { std::string out; out.reserve(glyph.size() * count); for (size_t i = 0; i < count; ++i) out += glyph; return out; };

    separatorStr += left;
    for (size_t i = 0; i < num_cells; ++i) {
        separatorStr += repeat(horizontal, cell_width + 2 * m_theme.cellPadding); // cell width + padding
        if (i < num_cells - 1) {
            separatorStr += middle;
        }
    }
    separatorStr += right;

    return separatorStr;
}

auto CliRenderer::drawCell(const Core::Cell &cell, const std::size_t cell_width) const -> std::string
{
    // Convert cell to string based on whether it's empty or has a value
    std::string cellStr;

    if (cell.isEmpty()) {
        cellStr = m_theme.emptyCellSymbol;
    } else {
        cellStr = std::to_string(cell.getValue().value());
    }

    // Pad the string to fit the cell width
    const size_t padding = cell_width - cellStr.length();

    // Align text based on theme settings
    switch (m_theme.textAlign) {
        case Theme::TextAlign::LEFT:
            cellStr += std::string(padding, ' ');
            break;
        case Theme::TextAlign::RIGHT:
            cellStr = std::string(padding, ' ') + cellStr;
            break;
        case Theme::TextAlign::CENTER:
            {
                const size_t leftPadding = padding / 2;
                const size_t rightPadding = padding - leftPadding;
                cellStr = std::string(leftPadding, ' ') + cellStr + std::string(rightPadding, ' ');
            }
            break;
    }

    // Crop if necessary
    if (cellStr.length() > cell_width) {
        cellStr = cellStr.substr(0, cell_width);
    }

    // Add padding
    cellStr = std::string(m_theme.cellPadding, ' ') + cellStr + std::string(m_theme.cellPadding, ' ');

    return cellStr;
}
