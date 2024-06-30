#include "uiMain.h"
#include "uiImageLoader.h"
#include "uiCell.h"
#include <iostream>
using namespace std;

ImageLoader imageLoader;

CellUI::CellUI() : texture(nullptr), positionX(0), positionY(0) {}

CellUI::~CellUI() {
    if (texture) SDL_DestroyTexture(texture);
    SDL_Quit();
}

void CellUI::renderCell(SDL_Renderer* renderer, int row, int col, int num) {
    SDL_Color borderColor = {0, 0, 0, 255};
    SDL_Color fillColor = {255, 255, 255, 255};

    SDL_Rect cell = {col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            
    SDL_SetRenderDrawColor(renderer, borderColor.r, borderColor.g, borderColor.b, borderColor.a);
    SDL_RenderFillRect(renderer, &cell);
            
    SDL_Rect innerCell = {col * CELL_SIZE + BORDER_WIDTH, row * CELL_SIZE + BORDER_WIDTH, 
                          CELL_SIZE - 2 * BORDER_WIDTH, CELL_SIZE - 2 * BORDER_WIDTH};
    SDL_SetRenderDrawColor(renderer, fillColor.r, fillColor.g, fillColor.b, fillColor.a);
    SDL_RenderFillRect(renderer, &innerCell);
            
    if (!imageLoader.textures.empty()) { // !imageLoader.textures.empty()
        SDL_RenderCopy(renderer, imageLoader.textures[num], nullptr, &innerCell);
    }

    SDL_RenderPresent(renderer);
}