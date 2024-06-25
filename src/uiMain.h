#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "backend.h"
#include <string>
#include <vector>
using namespace std;

class UI {
public:
    UI();
    ~UI();
    vector<SDL_Texture*> textures;
    vector<string> imagePaths;
    void generatePathsForVector();
    bool loadImages(const vector<string>& paths);
    bool initialize();
    void renderTitleScreen();
    void renderMainProgram(const Backend& backend, int num);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};

#endif