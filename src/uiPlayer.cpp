#include "uiPlayer.h"
#include <iostream>
using namespace std;

PlayerUI::PlayerUI() :  texture(nullptr) {}

PlayerUI::~PlayerUI() { 
    if (texture) SDL_DestroyTexture(texture);
    SDL_Quit();
}

bool PlayerUI::processInputP1(char& direction) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_w: direction = 'w'; break;
                case SDLK_s: direction = 's'; break;
                case SDLK_a: direction = 'a'; break;
                case SDLK_d: direction = 'd'; break;
                default: direction = '\0'; break;
            }
        }
    }
    return true;
}

bool PlayerUI::processInputP2(char& direction) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP: direction = 'w'; break;
                case SDLK_DOWN: direction = 's'; break;
                case SDLK_LEFT: direction = 'a'; break;
                case SDLK_RIGHT: direction = 'd'; break;
                default: direction = '\0'; break;
            }
        }
    }
    return true;
}

int PlayerUI::setPosition(int rowBackend, int colBackend, int cellSize) {
    this->positionY = rowBackend * cellSize;
    this->positionX = rowBackend * cellSize;
}