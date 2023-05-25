// MACROS for not implemented assertion

#include <stdio.h>

#if defined(__GNUC__) || (__clang__)
  #define TRAP() __builtin_trap()
#elif defined(_MSC_VER)
  #define TRAP() __debugbreak()
#else
  #error "Unsupported compiler"
#endif

#define NOT_IMPLEMENTED() \
  do { \
    printf("Error: Function or feature not implemented!\n"); \
    printf("File: %s\n", __FILE__); \
    printf("Line: %d\n", __LINE__); \
    TRAP(); \
  } while (0)

