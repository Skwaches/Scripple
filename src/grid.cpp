#include "grid.hpp"
#include "init.hpp"
#include <SDL3/SDL.h>

void Grid::refresh(){
	cell = {size.x/columns, size.y/rows};
	SDL_FPoint spaced_Size = {cell.x - spacing.x, cell.y - spacing.y};
	SDL_FPoint halfSpacing = {spacing.x/2.0f, spacing.y/2.0f};
	for (size_t i = 0; i < rects.size(); i++){
		int row = i / columns;
		int column = i % columns;
		rects[row * columns + column] = {
			position.x + halfSpacing.x + cell.x * column,
			position.y + halfSpacing.y + cell.y * row, 
			spaced_Size.x, spaced_Size.y
		};
	}
}

Grid::Grid(
		SDL_Point dimensions, 
		SDL_FPoint size,
		SDL_FPoint spacing,
		SDL_FPoint position
		):
	size(size), 
	position(position),
	rows(dimensions.x),
	columns(dimensions.y),
	cell({size.x / columns, size.y / rows}),
	spacing(spacing),
	rects(dimensions.x * dimensions.y, {0, 0 , 0, 0}),
	intensity(dimensions.x * dimensions.y) 
{
	refresh();
}

void Grid::resize(SDL_FPoint Nsize){
	size = Nsize;
	refresh();
};
void Grid::move(SDL_FPoint Nposition){
	position = Nposition;
	refresh();
};
void Grid::space(SDL_FPoint Nspacing){
	spacing = Nspacing;
	refresh();
};

void Grid::render(SDL_Renderer *renderer, std::vector<std::vector<SDL_Texture*>> textures) {
	//Warning This assumes all elements of texures are the same size!
	bool available = (textures.size() && textures[0].size() == rects.size()) ;
	for (size_t i = 0; i < rects.size(); i++){
		if (available){
			int step = intensity[i] * (textures.size() - 1);
			SDL_RenderTexture(renderer,  textures[step][i], NULL, &rects[i]);
		}
		else {
			Uint8 color = intensity[i] * 255;
			SDL_CHECK(SDL_SetRenderDrawColor(renderer, color, color, color, 255));
			SDL_CHECK(SDL_RenderFillRect(renderer, &rects[i]));
		}
	}
}

bool Grid::bounded(int row, int column){
	return (row >= 0 && column >= 0 && row < rows && column < columns);
}

void Grid::draw(SDL_FPoint cursor, bool state, int brush_radius) {
	int row = static_cast<int>(((cursor.y - position.y) / cell.y));
	int column = static_cast<int>(((cursor.x - position.x) / cell.x));

	if (!bounded(row,column))
		return;

	for (int i = row - brush_radius; i <= row + brush_radius; i++) {
		for (int j = column - brush_radius; j <= column + brush_radius; j++) {
			if (!bounded(i,j))
				continue;

			float distance = SDL_sqrt(
					SDL_pow(row - i, 2) + 
					SDL_pow(column - j, 2)
					);

			if (distance >= brush_radius)
				continue;

			float power = SDL_pow(1.0f - distance / brush_radius, 3);
			float &colour = intensity[i * columns + j];

			if (state) colour = SDL_min(colour + 0.2 * power, 1.0f);

			else colour = SDL_max(colour - 0.3 * power, 0.0f);
		}
	}
}

void Grid::clear(const bool state) {
	for (size_t pixel = 0; pixel < intensity.size(); pixel++){
		intensity[pixel] = state ? 0.8 : 0.0;
	}
}

