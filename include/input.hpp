#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_mouse.h>
#include <array>

class Inputs{
	 private:
		 std::array<bool, SDL_SCANCODE_COUNT> keys{}; 
		 std::array<bool, SDL_SCANCODE_COUNT> pkeys{}; //Previous keys state

		 std::array<bool, 6> mouse{};
		 std::array<bool, 6> pmouse{}; //Previous mouse state
		 SDL_FPoint mousePosition;
		 SDL_FPoint pmousePosition;
		 bool mouseMoved;
	 public:
		void newFrame();
		void loadEvent(const SDL_Event& event);

		bool keyClicked(SDL_Scancode key);
		bool keyHeld(SDL_Scancode key);
		bool keyReleased(SDL_Scancode key);

		bool mouseClicked(int button);
		bool mouseHeld(int button);
		bool mouseReleased(int button);
		
		//Amount which the cursor has moved
        SDL_FPoint cursorMotion();

		bool cursorMoved();

		SDL_FPoint cursor();
};

extern Inputs inputs;

