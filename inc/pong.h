#ifndef PONG_H
# define PONG_H

# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"
# include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
# include <iostream>

# define WIDTH		1024
# define HEIGHT		712

using namespace std;

class Wind
{
public:
	SDL_Window		*win;
	SDL_Surface		*surf;
	SDL_Event		event;
	TTF_Font		*font;
	Uint8			**space;
	Wind()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, \
			SDL_WINDOWPOS_CENTERED, 1024,\
			712, SDL_WINDOW_SHOWN);
		TTF_Init();
		surf = SDL_GetWindowSurface(win);
		// font = TTF_OpenFont("font/font.ttf", 80);
		space = new Uint8* [HEIGHT];
		for (int i = 0; i < HEIGHT; i++)
		{
			space[i] = new Uint8 [WIDTH];
			for(int j = 0; j < WIDTH; j++)
				space[i][j] = 0xf5f8ff;
		}

	}
};

#endif
