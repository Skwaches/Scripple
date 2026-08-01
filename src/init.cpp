#include "grid.hpp"
#include "load.hpp"
#include "machine.hpp"
#include "init.hpp"
#include "fonts.hpp"

SDL_AppResult APP_STATE = SDL_APP_CONTINUE;
Display SCREEN;
Grid GRID;
Grid FONTS( 
		{10,1},
		{100, static_cast<float>(SCREEN.size.y)},
		{20, 20},
		{GRID.size.x, 0}
		);

std::string baseFolder = "../assets/Number-Recognition";
Network MACHINE(baseFolder + "/Models/epoch-10.bin");

//Data
std::vector<std::vector<float>> Testing_data, Training_data;
std::vector<int> Testing_labels, Training_labels;

void load_Testing(){
	Testing_data = loadData(baseFolder + "/Testing/images.idx3-ubyte");
	Testing_labels = loadLabels(baseFolder + "/Testing/labels.idx1-ubyte");
}
void load_Training(){
 	Training_data = loadData(baseFolder + "/Training/images.idx3-ubyte");
	Training_labels = loadLabels(baseFolder + "/Training/labels.idx1-ubyte");
}

int maxEpoch = 10;
void test(){
	test(Testing_data, Testing_labels, Training_data, Training_labels, baseFolder + "/Models", maxEpoch);
}
void train(){
	train({784, 128, 128, 10}, Training_data, Training_labels, baseFolder + "/Models", maxEpoch);
}

void init(){
	SDL_SetAppMetadata("Cripple", "1.0", "Number Recognition model");
	SDL_CHECK(SDL_Init(SDL_INIT_VIDEO));
	SDL_CHECK(TTF_Init());
	SDL_CHECK(SDL_CreateWindowAndRenderer(
				SCREEN.title, 
				SCREEN.size.x,
				SCREEN.size.y,
				SCREEN.flags,
				&SCREEN.window, &SCREEN.renderer));
	SDL_CHECK(fonts(SCREEN.renderer));

	load_Testing();
	load_Training();
	GRID.space({0,0});
	MACHINE.normalise = hardMax;
}


void quit(){
	quitCUDA();
	SDL_DestroyWindow(SCREEN.window);
	SDL_DestroyRenderer(SCREEN.renderer);
	for(auto& textures: numberTextures){
		for(auto& texture: textures){
			SDL_DestroyTexture(texture);
		}
	}
	SDL_Quit();
}

