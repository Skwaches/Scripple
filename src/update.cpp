#include "grid.hpp"
#include "fonts.hpp"
#include "init.hpp"
#include "input.hpp"

void render(){
	SDL_CHECK(SDL_RenderClear(SCREEN.renderer));
	GRID.render(SCREEN.renderer, {});
	FONTS.render(SCREEN.renderer, numberTextures);
	SDL_CHECK(SDL_SetRenderDrawColor(SCREEN.renderer, 26, 77, 77, 255));
	SDL_CHECK(SDL_RenderPresent(SCREEN.renderer));
}

void update(){
	// Cap frame rate for drawing.
	static Uint64 previous = SDL_GetTicks(),
				  elapsed = 0;
	static const Uint64 fps = 240,
	 			 	    delay = 1000/fps;
	Uint64 current = SDL_GetTicks();
	elapsed += current - previous; 
	previous = current;
	bool timerPassed = elapsed >= delay;
	if (timerPassed) elapsed = 0;

	// Scribbling
	bool scribble = false;
	if (inputs.cursorMoved() && timerPassed) {
		if (inputs.mouseHeld(SDL_BUTTON_LEFT)) {
			GRID.draw(inputs.cursor(), true, 3);
			scribble = true;
		} 
		else if (inputs.mouseHeld(SDL_BUTTON_RIGHT)) {
			GRID.draw(inputs.cursor(), false, 5);
			scribble = true;
		}
	}
	if (inputs.keyClicked(SDL_SCANCODE_C)){
		GRID.clear(false);
		scribble = true;
	}

	if (inputs.keyClicked(SDL_SCANCODE_F)){
		GRID.clear(true);
		scribble = true;
	}
	if (scribble) {
		FONTS.intensity = MACHINE.evaluate(GRID.intensity.data);
	}

	if (inputs.keyClicked(SDL_SCANCODE_RETURN)){
		std::cout << FONTS.intensity << std::endl;
	}

}
