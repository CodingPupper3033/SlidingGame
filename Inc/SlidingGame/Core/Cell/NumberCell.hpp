//
// Created by codin on 1/15/26.
//

#ifndef SLIDINGGAME_NUMBERCELL_H
#define SLIDINGGAME_NUMBERCELL_H

#include "Cell.hpp"

namespace SlidingGame::Core
{
    class NumberCell: public Cell
    {
    public:
        explicit NumberCell(int number);

        [[nodiscard]] auto isEmpty() const -> bool override { return false; }
        [[nodiscard]] auto getValue() const -> int;

    private:
        const int m_number;
    };
}


#endif //SLIDINGGAME_NUMBERCELL_H