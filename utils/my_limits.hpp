#pragma once

namespace custom
{

    template <typename T>
    struct my_limits;

    template <>
    struct my_limits<double>
    {
        static constexpr double max() noexcept { return 1e10; }
        static constexpr double min() noexcept { return -1e10; }
    };
}
