#include "mimek/mimek.hpp"


int main(int argc, char* argv[]) {
  // Voiding for warnings
  (void) argc;
  (void) argv;

  // DEBUG prints
  printf("Screen Width:  %d\n", SCREEN_WIDTH);
  printf("Screen Height: %d\n", SCREEN_HEIGHT);

  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  bool engine_running = true;

  int exit_code = init_mim(window, renderer);
  if (exit_code != 0) {
    printf("Error! Exiting.\n");
    return exit_code;
  }

  run_mim(renderer, engine_running);

  clean_mim(window, renderer);

  return 0;
}
