#include <iostream>
#include <SDL3/SDL.h>
#include <boost/signals2.hpp>

#include <event.h>
#include <gui.h>
#include <app.h>

using KeySignal = boost::signals2::signal<void(SDL_Keycode)>;

SDL_Window* createWindow()
{
	constexpr size_t width = 800;
	constexpr size_t height = 600;

	SDL_Window* window = SDL_CreateWindow(
			"Lunari",
			width,
			height,
			SDL_WINDOW_RESIZABLE
	);

	if (!window)
	{
		std::cerr << "Window couldn't be created: " << SDL_GetError() << '\n';
		SDL_Quit();
		return nullptr;
	}
	return window;
}

SDL_Renderer* createRenderer(SDL_Window* window)
{
	SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

	if (!renderer)
	{
		std::cerr << SDL_GetError() << '\n';
		SDL_DestroyWindow(window);
		SDL_Quit();
		return nullptr;
	}
	return renderer;
}

int main()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		std::cerr << "SDL_Init failed: " << SDL_GetError() << '\n';
		return 1;
	}

	SDL_Window* window = createWindow();
	if (!window)
	{
		return 1;
	}

	SDL_Renderer* renderer = createRenderer(window);
	if (!renderer)
	{
		return 1;
	}

	KeySignal keySignal{};

	Event layer_event{keySignal};
	Gui layer_gui{layer_event, *renderer};
	App layer_app{layer_gui};

	/* Main-Loop */
	bool running{true};
	while (running)
	{
		SDL_Event event{};
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				running = false;
				break;
			}
			if (event.type == SDL_EVENT_KEY_DOWN)
				keySignal(event.key.key);
		}
		layer_app.manager().render();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
