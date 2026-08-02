#pragma once

#include "SDL3/SDL_render.h"
#include <vector>

extern std::vector<std::vector<SDL_Texture*>> numberTextures; 
bool fonts(SDL_Renderer* renderer);

