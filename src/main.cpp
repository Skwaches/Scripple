#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "init.hpp"
#include "input.hpp"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv){
	init();
	return APP_STATE;
}
#define max(a,b) a > b ? a:b;
#define min(a,b) a < b ? a:b;

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
	if(event->type == SDL_EVENT_QUIT){
		APP_STATE = SDL_APP_SUCCESS;
		return SDL_APP_SUCCESS;
	}
	else if(event->type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED){
		SCREEN.size.x = event->window.data1;
		SCREEN.size.y = event->window.data2;
		float smaller = min(SCREEN.size.x,SCREEN.size.y);
		GRID.resize({smaller, smaller});
		FONTS.move({GRID.size.x, 0});
		smaller = min(SCREEN.size.y/10.0, SCREEN.size.x - GRID.size.x);
		FONTS.resize({smaller ,static_cast<float>(SCREEN.size.y)});
	}
	inputs.loadEvent(*event);
	return APP_STATE;
}

SDL_AppResult SDL_AppIterate(void *appstate){
	update();
	render();
	inputs.newFrame();
	return APP_STATE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result){
	quit();
}
