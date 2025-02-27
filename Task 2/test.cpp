#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define COMMON_COLOR_MAX 255
#define COMMON_WINDOW_WIDTH 500
#define COMMON_WINDOW_HEIGHT (COMMON_WINDOW_WIDTH)

double common_get_secs(void) {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return ts.tv_sec + (1e-9 * ts.tv_nsec);
}
const double COMMON_FPS_GRANULARITY_S = 0.5;
double common_fps_last_time_s;
unsigned int common_fps_nframes;
void common_fps_init() {
    common_fps_nframes = 0;
    common_fps_last_time_s = common_get_secs();
}
void common_fps_update_and_print() {
    double dt, current_time_s;
    current_time_s = common_get_secs();
    common_fps_nframes++;
    dt = current_time_s - common_fps_last_time_s;
    if (dt > COMMON_FPS_GRANULARITY_S) {
        printf("FPS = %f\n", common_fps_nframes / dt);
        common_fps_last_time_s = current_time_s;
        common_fps_nframes = 0;
    }
}

#define MAX_STRING_LEN 4

/*
- x, y: upper left corner of string
- rect output Width and height contain rendered dimensions.
*/
void render_text(
    SDL_Renderer *renderer,
    int x,
    int y,
    const char *text,
    TTF_Font *font,
    SDL_Rect *rect,
    SDL_Color *color
) {
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = TTF_RenderText_Solid(font, text, *color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    rect->x = x;
    rect->y = y;
    rect->w = surface->w;
    rect->h = surface->h;
    /* This is wasteful for textures that stay the same.
     * But makes things less stateful and easier to use.
     * Not going to code an atlas solution here... are we? */
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, rect);
    SDL_DestroyTexture(texture);
}

int main(int argc, char **argv) {
    SDL_Color color;
    SDL_Event event;
    SDL_Rect rect;
    SDL_Renderer *renderer;
    SDL_Window *window;
    char *font_path, text[MAX_STRING_LEN];

    /* CLI arguments. */
    if (argc == 1) {
        font_path = "FreeSans.ttf";
    } else if (argc == 2) {
        font_path = argv[1];
    } else {
        fprintf(stderr, "error: too many arguments\n");
        exit(EXIT_FAILURE);
    }

    /* initialize variables. */
    color.r = COMMON_COLOR_MAX;
    color.g = COMMON_COLOR_MAX;
    color.b = COMMON_COLOR_MAX;
    color.a = COMMON_COLOR_MAX;

    /* Init window. */
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(
        COMMON_WINDOW_WIDTH,
        COMMON_WINDOW_WIDTH,
        0,
        &window,
        &renderer
    );

    /* Init TTF. */
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("lazy.ttf", 28);
    if (font == NULL) {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }

    /* Main loop. */
    common_fps_init();
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            break;
        }

        /* Use TTF. */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        render_text(renderer, 0, 0,               "hello", font, &rect, &color);
        render_text(renderer, 0, rect.y + rect.h, "world", font, &rect, &color);
        snprintf(text, MAX_STRING_LEN, "%u", (unsigned int)(time(NULL) % 1000));
        render_text(renderer, 0, rect.y + rect.h, text, font, &rect, &color);
        SDL_RenderPresent(renderer);

        common_fps_update_and_print();
    }

    /* Cleanup. */
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
