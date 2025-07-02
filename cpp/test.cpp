#include "test.h"

#include <array>

static constexpr std::size_t max_precomuted_fibonacci = 30;

template<std::size_t N>
static auto constexpr initialize_fibonacci_numbers(void)
{
    static_assert(N >= 2);
    std::array<long, N> values{0, 1};
    for (std::size_t n = 2; n < N; ++n)
    {
        values[n] = values[n - 1] + values[n - 2];
    }
    return values;
}

long fibonacci(long n) {
    static constexpr auto fibonacci_number = initialize_fibonacci_numbers<max_precomuted_fibonacci>();

    if (n <= 1) return n;
    else if (n <= max_precomuted_fibonacci) return fibonacci_number[n];
    else return fibonacci(n - 1) + fibonacci(n - 2);
}
