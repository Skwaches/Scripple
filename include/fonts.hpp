#pragma once

#include <SDL3/SDL.h>
#include <vector>
#include <SDL3_ttf/SDL_ttf.h>

extern std::vector<std::vector<SDL_Texture*>> numberTextures; 
bool fonts(SDL_Renderer* renderer);

