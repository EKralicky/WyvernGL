#pragma once

#define BIT(x) (1 << x) // Bit shift 1 by x places

#define WYV_DEBUG_BREAK __debugbreak()
#define WYV_ASSERT(assert_on, msg) if (!assert_on) { std::cout << "Assertion Failed: " << msg << "\n"; WYV_DEBUG_BREAK; }

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}