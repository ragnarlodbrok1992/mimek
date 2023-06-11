#ifndef _H_MACROS
#define _H_MACROS

#include "const.hpp"

#include <stdio.h>
#include <cassert>


// MACRO for compile time assertion
#define COMPILETIME_NOT_IMPLEMENTED static_assert(false, "COMPILETIME CHECK: Not implemented!");


// MACROS for not implemented assertion

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

#define BAD_RUNTIME_EXECUTION_PATH() \
  do { \
    assert(RUNTIME_EXECTION_PATH_ERROR); \
  } while (0)

#endif /* _H_MACROS */

