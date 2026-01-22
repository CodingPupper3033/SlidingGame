//
// Created by codin on 1/15/26.
//

#ifndef SLIDINGGAME_CELL_H
#define SLIDINGGAME_CELL_H

namespace SlidingGame::Core
{
    class Cell
    {
    public:
        virtual ~Cell() = default;

        [[nodiscard]] virtual auto IsEmpty() const -> bool = 0;
    };
}

#endif //SLIDINGGAME_CELL_H