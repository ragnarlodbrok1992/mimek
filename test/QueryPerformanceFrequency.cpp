#include <Windows.h>
#include <stdio.h>

int main() {

  LARGE_INTEGER frequency;

  if (!QueryPerformanceFrequency(&frequency)) {
    printf("Quering frequency failed, exiting!\n");
    return 1;
  }

  // If successful
  printf("Frequency is %lld\n", frequency);

  return 0;
}
