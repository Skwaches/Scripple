#include "input.hpp"

Inputs inputs;
void Inputs::newFrame(){
	pkeys = keys;
	pmouse = mouse;
	pmousePosition = mousePosition;
	mouseMoved = false;
}
		
void Inputs::loadEvent(const SDL_Event& event){
	switch(event.type){
		case SDL_EVENT_KEY_DOWN: 
			keys[event.key.scancode] = true;
			break;

		case SDL_EVENT_KEY_UP: 
			keys[event.key.scancode] = false;
			break;

		case SDL_EVENT_MOUSE_MOTION:
			mousePosition.x = event.motion.x;
			mousePosition.y = event.motion.y;
			mouseMoved = true;
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			if(event.button.button < mouse.size())
				mouse[event.button.button] = true;
			break;
		
		case SDL_EVENT_MOUSE_BUTTON_UP:
			if(event.button.button < mouse.size())
				mouse[event.button.button] = false;
			break;
		default:
			break;
	}
}

bool Inputs::keyHeld(SDL_Scancode key){
	return keys[key];
}
bool Inputs::keyClicked(SDL_Scancode key){
	return keys[key] && !pkeys[key];
}
bool Inputs::keyReleased(SDL_Scancode key){
	return !keys[key] && pkeys[key];
}

bool Inputs::mouseClicked(int button){
	return mouse[button] && !pmouse[button];
}
bool Inputs::mouseHeld(int button){
	return mouse[button]; 
}
bool Inputs::mouseReleased(int button){
	return !mouse[button] && pmouse[button];
}
bool Inputs::cursorMoved(){
	return mouseMoved;
}
SDL_FPoint Inputs::cursorMotion(){
	return {mousePosition.x - pmousePosition.x, mousePosition.y - pmousePosition.y};
}
SDL_FPoint Inputs::cursor(){
	return mousePosition;
}
