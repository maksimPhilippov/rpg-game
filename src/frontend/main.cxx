
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "vulkanEngine.h"

VulkanEngine VulkanEngineInstance = new VulkanEngine();

static void init_vulkan() {
    VulkanEngineInstance.init_vulkan();
}

static void draw_triangle() {
    return;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    const int windowHeight = 400;
    const int windowWidth = 400;

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindow("Rpg game", windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN)) {
        return SDL_APP_FAILURE;
    }
    init_vulkan();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    draw_triangle();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    switch (event->type) {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    case SDL_EVENT_KEY_DOWN:
        return SDL_APP_CONTINUE;
    default:
        break;
    }
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    return;
}
