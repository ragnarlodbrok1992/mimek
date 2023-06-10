#include "mimek.hpp"

#include "Utils.hpp"
#include "Types.hpp"

static Mouse_Pointer mouse_pointer;
static Button_Vec button_vec;

int init_mim(SDL_Window*& engine_window, SDL_Renderer*& engine_renderer) {
  printf("Initialization.\n");

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL initialization failed: %s\n", SDL_GetError());
    return 1;
  }

  // Create a window
  engine_window = SDL_CreateWindow(
      TITLE_BAR,
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, 
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN);
  if (engine_window == nullptr) {
    printf("Failed to create SDL window: %s\n", SDL_GetError());
    return 1;
  }

  // Create a renderer
  engine_renderer = SDL_CreateRenderer(
      engine_window,
      -1,
      SDL_RENDERER_ACCELERATED);
  if (engine_renderer == nullptr) {
    printf("Failed to create SDL renderer: %s\n", SDL_GetError());
    return 1;
  }
  return 0;
}

void run_mim(SDL_Renderer*& engine_renderer, bool& running) {
  printf("Running.\n");
  printf("Engine running var: %s\n", running ? "true" : "false");

  SDL_Event event;

  // Initialize elements
  init_ui_elements_buttons_mim(button_vec);

  // @TODO: Render fill polygon scanline algorithm
  // DEBUG - test ymin, ymax, xmin, xmax
  Point2D_Vec test_points_vec;
  test_points_vec.push_back({10, 10});
  test_points_vec.push_back({2, 10});
  test_points_vec.push_back({10, 20});
  test_points_vec.push_back({20, 35});

  int x_min, x_max, y_min, y_max;
  utils_mim_yminmax_xminmax_from_points2d_vec(test_points_vec, y_min, y_max, x_min, x_max);
  
  // DEBUG print
  printf("Y min: %d\n", y_min);
  printf("Y max: %d\n", y_max);
  printf("X min: %d\n", x_min);
  printf("X max: %d\n", x_max);

  while(running) {
    // Handling events
    while (SDL_PollEvent(&event)) {
      // Quiting event
      if (event.type == SDL_QUIT) {
        running = false;
      }

      // Handling mouse
      if (event.type == SDL_MOUSEBUTTONDOWN) {
        mouse_pointer.mouse_state = SDL_GetMouseState(&mouse_pointer.pos_x, &mouse_pointer.pos_y);

#ifdef DEBUG_CODE_INPUT
        print_mouse_state(mouse_pointer);
#endif

        // Selecting madafakin buttons
        Button* selected_button = select_button(button_vec, mouse_pointer.pos_x, mouse_pointer.pos_y); 
        printf("Selected button: 0x%p\n", selected_button);

        // DEBUG - changing color of button
        if (selected_button != NULL) button_set_color(*selected_button, {0, 255, 127, 255});

      }
      
      // Keyboard presses
      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          running = false;
        }
      }
    }

    // Clearning the screen
    SDL_SetRenderDrawColor(engine_renderer, 0, 0, 0, 255);
    SDL_RenderClear(engine_renderer);

    // Render code goes here
    render_ui_buttons(engine_renderer, button_vec);

    // Test rendering
    mim_render(engine_renderer);

    // Update the screen
    SDL_RenderPresent(engine_renderer);
  }
}

void clean_mim(SDL_Window*& engine_window, SDL_Renderer*& engine_renderer) {
  printf("Cleaning.\n");

  SDL_DestroyRenderer(engine_renderer);
  SDL_DestroyWindow(engine_window);
  SDL_Quit();

}



void test_mim() {
  NOT_IMPLEMENTED();
}

