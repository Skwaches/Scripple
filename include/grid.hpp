#pragma once
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "matrix.hpp"

class Grid {
	public:
		SDL_FPoint size;
		SDL_FPoint position;
		int rows, columns;
		SDL_FPoint cell;
		SDL_FPoint spacing;
		std::vector<SDL_FRect> rects;

	public:
		Matrix intensity;
		Grid(
				SDL_Point dimensions = {28, 28},
				SDL_FPoint size = {1200, 1200},
				SDL_FPoint spacing = {10, 10},
				SDL_FPoint position = {0.0, 0.0}
			);
		bool bounded(int row, int column);
		void render(
				SDL_Renderer *renderer,
				std::vector<std::vector<SDL_Texture*>> textures
				); 
		void draw(SDL_FPoint mouse_position, bool state, int brush_radius);
		void clear(const bool state);

		void resize(SDL_FPoint size);
		void move(SDL_FPoint position);
		void space(SDL_FPoint spaces);
		void refresh();
};
