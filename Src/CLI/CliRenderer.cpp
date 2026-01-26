//
// Created by codin on 1/25/26.
//

#include "CLI/CliRenderer.h"

#include <iomanip>
#include <iostream>
#include <string>

void SlidingGame::CLI::CliRenderer::renderBoard(const Core::SlidingGame &game)
{
    const size_t width = game.getWidth();
    const size_t height = game.getHeight();

    const size_t cellWidth = 5; // total characters per cell (keeps previous alignment)

    // box-drawing characters (UTF-8)
    const std::string TL  = "┌";
    const std::string TR  = "┐";
    const std::string BL  = "└";
    const std::string BR  = "┘";
    const std::string H   = "─";
    const std::string V   = "│";
    const std::string TSEP = "┬";
    const std::string BSEP = "┴";
    const std::string LSEP = "├";
    const std::string RSEP = "┤";
    const std::string CSEP = "┼";

    // build a horizontal segment that repeats the UTF-8 horizontal glyph cellWidth times
    std::string hor;
    hor.reserve(H.size() * cellWidth);
    for (size_t i = 0; i < cellWidth; ++i) hor += H;

    // Top border
    std::cout << TL;
    for (size_t x = 0; x < width; ++x) {
        std::cout << hor;
        std::cout << (x + 1 == width ? TR : TSEP);
    }
    std::cout << '\n';

    for (size_t y = 0; y < height; ++y) {
        // Row with cells
        std::cout << V;
        for (size_t x = 0; x < width; ++x) {
            const Core::Cell &cell = game.at(x, y); // explicit fetch
            if (cell.isEmpty()) {
                std::cout << "  .  "; // 5 chars: two spaces, dot, two spaces
            } else {
                std::cout << ' ' << std::setw(3) << cell.getValue().value() << ' ';
            }
            std::cout << V;
        }
        std::cout << '\n';

        // Inter-row separator (not after last row)
        if (y + 1 < height) {
            std::cout << LSEP;
            for (size_t x = 0; x < width; ++x) {
                std::cout << hor;
                std::cout << (x + 1 == width ? RSEP : CSEP);
            }
            std::cout << '\n';
        }
    }

    // Bottom border
    std::cout << BL;
    for (size_t x = 0; x < width; ++x) {
        std::cout << hor;
        std::cout << (x + 1 == width ? BR : BSEP);
    }
    std::cout << '\n';
}
