// MACROS for not implemented assertion

#include "const.hpp"

#include <stdio.h>
#include <cassert>

#if defined(__GNUC__) || (__clang__)
  #define TRAP() __builtin_trap()
#elif defined(_MSC_VER)
  #define TRAP() __debugbreak()
#else
  #error "Unsupported compiler"
#endif

#define NOT_IMPLEMENTED() \
  do { \
    assert(FUNCTION_OR_FEATURE_NOT_IMPLEMENTED); \
  } while (0)

