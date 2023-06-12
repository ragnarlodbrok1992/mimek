#include "mimek/mimek.hpp"


int main(int argc, char* argv[]) {
  // Voiding for warnings
  (void) argc;
  (void) argv;

  // DEBUG prints
  printf("Screen Width:  %d\n", SCREEN_WIDTH);
  printf("Screen Height: %d\n", SCREEN_HEIGHT);

  // Create window, renderer, engine_running variable
  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;
  bool engine_running = true;

  // Run init_mim function
  int exit_code = init_mim(window, renderer);
  if (exit_code != 0) {
    printf("Error! Exiting.\n");
    return exit_code;
  }

  // Run_mim - inner engine loop
  run_mim(renderer, engine_running);

  // Clean up engine
  clean_mim(window, renderer);

  return 0;
}

