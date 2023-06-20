#include <stdio.h>
#include <cstdint>

extern "C" uint64_t __rdtscp_proc();

int main() {
  uint64_t start = __rdtscp_proc();

  // Measured code goes here
  printf("How long does it take to print out Mimek engine?\n");

  uint64_t end = __rdtscp_proc();
  uint64_t elapsed = end - start;

  printf("Elapsed time of measured code: %lld\n", elapsed);

  return 0;
}
