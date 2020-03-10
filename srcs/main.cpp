#include "../inc/pong.h"

void	draw_space(Wind *window)
{
	int		x;
	int		y;
	Uint8	*pic;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pic = (Uint8 *)window->surf->pixels + y * window->surf->pitch +
			x * window->surf->format->BytesPerPixel;
			*pic = window->space[y][x];
			x++;
		}
		y++;
	}	
}

void	event(SDL_Event	event)
{
	if (((event.key.type == SDL_KEYDOWN &&\
			event.key.keysym.sym == SDLK_ESCAPE)\
			|| event.type == SDL_QUIT))
		exit(1);	
}

int		main(int ac, char **av)
{
	Wind *window = new Wind();

	while (1)
	{
		while (SDL_PollEvent(&window->event))
			event(window->event);
		draw_space(window);
		SDL_UpdateWindowSurface(window->win);
	}

	return (0);
}