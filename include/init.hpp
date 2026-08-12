#pragma once
#include "grid.hpp"
#include "think.hpp"
#include <SDL3/SDL.h>

extern SDL_AppResult APP_STATE;
#define SDL_CHECK(expression) do {\
	bool success= expression;\
	if(!success){\
		SDL_Log("SDL Runtime Error! , %s:%i, %s\n", __FILE__, __LINE__, SDL_GetError());\
		APP_STATE = SDL_APP_FAILURE;\
	}\
} while(0)

typedef struct Display{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Point size = {600, 500};
	SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE;
	const char* title = "Walk young one!";
}Display;

extern Display SCREEN;
extern Grid GRID;
extern Grid FONTS;
extern Network MACHINE;

void init();
void quit();
void update();
void render();
