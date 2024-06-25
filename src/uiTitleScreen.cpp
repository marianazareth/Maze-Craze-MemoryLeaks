#include "uiTitleScreen.h"
#include <iostream>
using namespace std;

TitleScreen::TitleScreen() : backgroundImage(nullptr) {}

TitleScreen::~TitleScreen() {
    if (backgroundImage) SDL_DestroyTexture(backgroundImage);
}

void TitleScreen::renderTitleScreen(SDL_Renderer* renderer) {
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, backgroundImage, nullptr, nullptr);

    SDL_Rect playButton = {600, 1665, 700, 200};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &playButton);

    SDL_RenderPresent(renderer);
}

