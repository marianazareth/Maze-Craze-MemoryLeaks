#ifndef UI_TITLESCREEN_H
#define UI_TITLESCREEN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
using namespace std;

class TitleScreen {
public:
    TitleScreen();
    ~TitleScreen();
    void renderTitleScreen(SDL_Renderer* renderer);

private:
    SDL_Texture* backgroundImage;
};

#endif