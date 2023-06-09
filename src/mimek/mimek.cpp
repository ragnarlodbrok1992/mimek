#include "mimek.hpp"

#include "Utils.hpp"
#include "Types.hpp"

static Mouse_Pointer mouse_pointer;
static Layout_Vec layout_vec;

// Initialize UI handlers
static Button* hovered_button = NULL;
static Button* worked_button = NULL;
static Layout* hovered_layout = NULL;
static Layout* worked_layout = NULL;

static Layout default_layout;

static void* sticked_ui_element = NULL;

static bool left_mouse_button_pressed = false;

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
  if (engine_window == NULL) {
    printf("Failed to create SDL window: %s\n", SDL_GetError());
    return 1;

  }

  // Create a renderer
  engine_renderer = SDL_CreateRenderer(
      engine_window,
      -1,
      SDL_RENDERER_ACCELERATED);
  if (engine_renderer == NULL) {
    printf("Failed to create SDL renderer: %s\n", SDL_GetError());
    return 1;
  }

  // Initialize elements
  // init_ui_elements_buttons_mim(button_vec);
  // init_ui_elements_layout_mim(default_layout);

  printf("Default layout: %p\n", &default_layout);
  default_layout = create_default_layout_mim();
  printf("Default layout: %p\n", &default_layout);

  // Push back default_layout to layout_vec
  layout_vec.push_back(default_layout);

  return 0;
}

void run_mim(SDL_Renderer*& engine_renderer, bool& running) {
  printf("Running.\n");
  printf("Engine running var: %s\n", running ? "true" : "false");

  SDL_Event event;


  while(running) {
    // Handling events
    while (SDL_PollEvent(&event)) {
      // Quiting event
      if (event.type == SDL_QUIT) {
        running = false;
      }

      // Handling mouse
      // MOUSE - pressing mouse button (left and right for now)
      if (event.type == SDL_MOUSEBUTTONDOWN) {
        // Mouse button pressed
        left_mouse_button_pressed = true;

        mouse_pointer.mouse_state = SDL_GetMouseState(&mouse_pointer.pos_x, &mouse_pointer.pos_y);

#ifdef DEBUG_CODE_INPUT
#if 0
        print_mouse_state(mouse_pointer);
#endif
#endif 

        // Selecting madafakin buttons
        // Changing from Clicked to clicked or focused
#if 1
        Layout* selected_layout = select_layout(layout_vec, mouse_pointer.pos_x, mouse_pointer.pos_y);

        if (selected_layout != NULL) {
          layout_click(*selected_layout, mouse_pointer.pos_x, mouse_pointer.pos_y);
          
          if (selected_layout->is_sticked) {
            sticked_ui_element = selected_layout;
          }
          else {
            sticked_ui_element = NULL;
          }
        }

        Button* selected_button = select_button_from_layout(layout_vec, mouse_pointer.pos_x, mouse_pointer.pos_y); 
        if (selected_button != NULL) button_click(*selected_button);
#endif
      }

      if (event.type == SDL_MOUSEMOTION) {
        if (left_mouse_button_pressed && sticked_ui_element != NULL) {
          Layout* layout = (struct Layout*) sticked_ui_element;
          update_layout_position(layout, event.motion.xrel, event.motion.yrel);
        }
      }
      
      if (event.type == SDL_MOUSEBUTTONUP) {
        left_mouse_button_pressed = false;
        sticked_ui_element = NULL;
      }
      
      // Keyboard presses
      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          running = false;
        }
        if (event.key.keysym.sym == SDLK_q) {
          running = false;
        }
      }
    }

    // End of event loop

    // Check mouse hovering @TODO should this be done in every frame? Use QuadTree for checking for UI elements
#if 1
    mouse_pointer.mouse_state = SDL_GetMouseState(&mouse_pointer.pos_x, &mouse_pointer.pos_y);
    hovered_button = select_button_from_layout(layout_vec, mouse_pointer.pos_x, mouse_pointer.pos_y);

    if (hovered_button != NULL) {
      worked_button = hovered_button;
      if (worked_button->status != STATUS::CLICKED) worked_button->status = STATUS::FOCUSED;
    } else if (worked_button != NULL) {
      if (worked_button->status != STATUS::CLICKED) worked_button->status = STATUS::UN_FOCUSED;
      worked_button = NULL;
    }
#endif

    // Check if mouse button is held and if there is a stickied element
#if 1

    if (left_mouse_button_pressed) {
      if (sticked_ui_element != NULL) {
      }
    }

#endif

    // Clearning the screen
    SDL_SetRenderDrawColor(engine_renderer, 0, 0, 0, 255);
    SDL_RenderClear(engine_renderer);

    // Render code goes here
    // Render layout
    render_layout_vec(engine_renderer, layout_vec);

    // Render buttons
    // render_ui_buttons(engine_renderer, button_vec);

    // Test rendering
    mim_render(engine_renderer);

    // Update the screen
    SDL_RenderPresent(engine_renderer);
  }
}

void clean_mim(SDL_Window*& engine_window, SDL_Renderer*& engine_renderer) {
  printf("Cleaning.\n");

  // Deleting heap stuff
  // delete default_layout;

  printf("Heap cleaned!\n");

  SDL_DestroyRenderer(engine_renderer);
  SDL_DestroyWindow(engine_window);
  SDL_Quit();

}

void test_mim() {
  NOT_IMPLEMENTED();
}

