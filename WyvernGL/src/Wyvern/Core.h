#pragma once

#define BIT(x) (1 << x) // Bit shift 1 by x places


#define BIND_VOID_FN_NOPARAM(instance, x) std::bind(&x, instance)

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}