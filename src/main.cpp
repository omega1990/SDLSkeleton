#include <iostream>

#include "SDL.h" 
#include "../inc/Defaults.hpp"

SDL_Window* window;
SDL_Renderer* renderer;

int
SDLInit(
bool &retflag)
{
	retflag = true;
	if ((SDL_Init(SDL_INIT_VIDEO) == -1))
	{
		std::cout << "Could not initialize SDL:" << SDL_GetError() << std::endl;
		return -1;
	}

	std::cout << "SDL initialized." << SDL_GetError() << std::endl;

	if (SDL_CreateWindowAndRenderer(
		static_cast<int>(DEFAULT_HEIGHT),
		static_cast<int>(DEFAULT_WIDTH),
		0,
		&window,
		&renderer) == -1)
	{
		std::cout << "Could not create window and renderer" << SDL_GetError() << std::endl;
		return -1;
	}

	retflag = false;
	return{};
}

int main(int argc, char* argv[])
{
	bool retflag;
	int retval = SDLInit(retflag);
	if (retflag) return retval;

	bool loop = true;
	while (loop)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				loop = false;
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				default:
					break;
				}
			}
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}

	/* Shutdown all subsystems */
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}