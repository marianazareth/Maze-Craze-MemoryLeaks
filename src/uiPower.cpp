#include "uiMain.h"
#include "uiCell.h"
#include "uiImageLoader.h"
#include "uiPower.h"
#include <iostream>
using namespace std;

ImageLoader imageLoader;

PowerUI::PowerUI() : texture(nullptr), positionX(0), positionY(0) {}

PowerUI::~PowerUI() {
    if (texture) SDL_DestroyTexture(texture);
    SDL_Quit();
}

void PowerUI::renderPower(SDL_Renderer* renderer, int row, int col, int num) {         
    SDL_Rect powerForCell = {col * CELL_SIZE + BORDER_WIDTH, row * CELL_SIZE + BORDER_WIDTH, 
                          CELL_SIZE - 2 * BORDER_WIDTH, CELL_SIZE - 2 * BORDER_WIDTH};
            
    if (!imageLoader.textures.empty()) {
        SDL_RenderCopy(renderer, imageLoader.textures[num], nullptr, &powerForCell);
    }

    SDL_RenderPresent(renderer);
}