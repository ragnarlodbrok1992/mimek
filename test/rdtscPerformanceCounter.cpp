#include <stdio.h>
#include <cstdint>

uint64_t rdtsc() {
  uint32_t low, high;
  // @TODO: fix this
  // asm (volatile("rdtsc" : "=a" (low), "=d" (high)));
  return ((uint64_t) high << 32) | low;
}

int main() {
  uint64_t start = rdtsc();

  // Measured code goes here

  uint64_t end = rdtsc();
  uint64_t elapsed = end - start;

  printf("Elapsed time of measured code: %d\n", elapsed);

  return 0;
}
