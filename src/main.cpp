#include "mimek/mimek.hpp"

int main(int argc, char* argv[]) {
  // DEBUG prints
  // std::cout << SCREEN_WIDTH  << std::endl;
  // std::cout << SCREEN_HEIGHT << std::endl;

  init_mim();

  run_mim();

  return 0;
}
