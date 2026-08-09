#include <iostream>
#include <SDL3/SDL.h>
#include <boost/signals2.hpp>

#include "event.h"

using KeySignal = boost::signals2::signal<void(SDL_Keycode)>;

int main() {
    KeySignal keySignal{};

    Event layer_event{keySignal};

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "SDL_Init fehlgeschlagen: " << SDL_GetError() << '\n';
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
            "Pacman",
            800,
            600,
            SDL_WINDOW_RESIZABLE
    );

    if (!window)
    {
        std::cerr << "Fenster konnte nicht erstellt werden: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    if (!renderer) {
        std::cerr << SDL_GetError() << '\n';
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

    SDL_FRect rect{

            100.0f,

            100.0f,

            50.0f,

            50.0f

    };

    SDL_RenderFillRect(renderer, &rect);

    // Fertiges Bild anzeigen

    SDL_RenderPresent(renderer);

    SDL_Event event{};
    bool running{true};
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
                break;
            }
            if (event.type == SDL_EVENT_KEY_DOWN) {
                keySignal(event.key.key);
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
