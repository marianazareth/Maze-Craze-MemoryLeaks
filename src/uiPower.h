#ifndef POWERUI_H
#define POWERUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class PowerUI {
public:
    PowerUI();
    ~PowerUI();
    void renderPower(SDL_Renderer* renderer, int row, int col, int num);

private:
    SDL_Texture* texture;
    int positionX;
    int positionY;
};

#endif