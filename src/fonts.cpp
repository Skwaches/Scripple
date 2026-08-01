#include "fonts.hpp"
#include "SDL3_ttf/SDL_ttf.h"
#include <string>
#include <format>

int steps = 2;
std::vector<std::vector<SDL_Texture*>> numberTextures(steps); 

bool fonts(SDL_Renderer* renderer){
	TTF_Font* font = TTF_OpenFont("../assets/0xProtoNerdFont-Bold.ttf", 80);
	if(!font)
		return false;
	SDL_Color correct =   { 255, 255, 255, SDL_ALPHA_OPAQUE};
	SDL_Color incorrect = { 0, 0, 0, SDL_ALPHA_OPAQUE};

	SDL_Color difference = { 
		static_cast<Uint8>(correct.r - incorrect.r),
		static_cast<Uint8>(correct.g - incorrect.g),
		static_cast<Uint8>(correct.b - incorrect.b),
		static_cast<Uint8>(correct.a - incorrect.a)
	};

	SDL_Surface* number;
	std::string text;
	SDL_Texture* texture;
	for(int i = 0; i<steps;i++){
		SDL_Color color;
		color.r = incorrect.r + difference.r * i/(steps-1);
		color.g = incorrect.g + difference.g * i/(steps-1);
		color.b = incorrect.b + difference.b * i/(steps-1);
		color.a = incorrect.a + difference.a * i/(steps-1);
		numberTextures[i] = std::vector<SDL_Texture*>();
		for (int n =0; n < 10; n++){
			text = std::format("{}", n);
			number = TTF_RenderText_Blended(font, text.c_str(), 0, color);
			if(number){
				texture = SDL_CreateTextureFromSurface(renderer,number);
				SDL_DestroySurface(number);
				numberTextures[i].push_back(texture);
			}
			else{
				SDL_Log("Hiiii, sorry about this...");
				return false;
			}

		}
	}
	TTF_CloseFont(font);
	return true;
}
