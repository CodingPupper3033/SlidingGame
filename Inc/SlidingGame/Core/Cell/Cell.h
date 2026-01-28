//
// Created by codin on 1/15/26.
//

#ifndef SLIDINGGAME_CELL_H
#define SLIDINGGAME_CELL_H
#include <optional>
#include <string_view>

namespace SlidingGame::Core
{
    class Cell
    {
    public:
        Cell() = default;

        virtual ~Cell() = default;

        [[nodiscard]] virtual auto isEmpty() const -> bool = 0;
        [[nodiscard]] virtual auto getValue() const -> std::optional<int> { return std::nullopt; }
    };
}

#endif //SLIDINGGAME_CELL_H