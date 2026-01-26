//
// Created by codin on 1/15/26.
//

#ifndef SLIDINGGAME_EMPTYCELL_H
#define SLIDINGGAME_EMPTYCELL_H

#include "Cell.hpp"

namespace SlidingGame::Core
{
class EmptyCell: public Cell
{
public:
    EmptyCell() = default;

    [[nodiscard]] auto isEmpty() const -> bool override
    {
        return true;
    }
};
} // namespace SlidingGame::Core

#endif //SLIDINGGAME_EMPTYCELL_H