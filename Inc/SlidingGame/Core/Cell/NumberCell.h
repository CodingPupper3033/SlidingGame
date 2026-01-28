//
// Created by codin on 1/15/26.
//

#ifndef SLIDINGGAME_NUMBERCELL_H
#define SLIDINGGAME_NUMBERCELL_H

#include "Cell.h"

namespace SlidingGame::Core
{
    class NumberCell: public Cell
    {
    public:
        explicit NumberCell(const int number): m_number(number) {}

        [[nodiscard]] auto isEmpty() const -> bool override { return false; }
        [[nodiscard]] auto getValue() const -> std::optional<int> override { return m_number; }

    private:
        const int m_number;
    };
}


#endif //SLIDINGGAME_NUMBERCELL_H