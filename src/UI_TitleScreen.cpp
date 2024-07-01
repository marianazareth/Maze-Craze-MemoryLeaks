#include "UI_ImageLoader.h"
#include "UI_TitleScreen.h"
#include <iostream>
using namespace std;

void UI_TitleScreen::runTitleScreen(SDL_Renderer* renderer) {
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, imageLoader.textures[0], nullptr, nullptr);

    SDL_Rect playButton = {600, 1665, 700, 200};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &playButton);

    SDL_RenderPresent(renderer);
}

bool isPointInRect(int x, int y, SDL_Rect rect) {
    return x > rect.x && x < rect.x + rect.w && y > rect.y && y < rect.y + rect.h;
}

bool UI_TitleScreen::handleEvents(SDL_Event& event) {
    bool returnValue = false;
    SDL_Rect playButton = {600, 665, 700, 200};

    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);

        if (isPointInRect(x, y, playButton)) {
            returnValue = true;
        }
    }
    return returnValue;
}


