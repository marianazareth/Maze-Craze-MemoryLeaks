#ifndef PLAYERUI_H
#define PLAYERUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#define BORDER_WIDTH 2
using namespace std;

class CellUI {
public:
    CellUI();
    ~CellUI();
    void renderCell(SDL_Renderer* renderer, int row, int col, int num);

private:
    SDL_Texture* texture;
    int positionX;
    int positionY;
};

#endif