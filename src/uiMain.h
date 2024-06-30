#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
#define CELL_SIZE 50
using namespace std;

class UI {
public:
    UI();
    ~UI();
    bool initialize();
    void renderMainProgram(const auto& grid, int num);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};

#endif