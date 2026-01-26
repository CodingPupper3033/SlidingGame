//
// Created by codin on 1/15/26.
//

#include "../../../Inc/SlidingGame/Core/Cell/NumberCell.hpp"

namespace SlidingGame::Core
{
    NumberCell::NumberCell(const int number): m_number(number)
    {
    }

    auto NumberCell::getValue() const -> int
    {
        return m_number;
    }
}