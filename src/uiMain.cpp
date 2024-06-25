#include "uiMain.h"
#include <iostream>
using namespace std;

UI::UI() : window(nullptr), renderer(nullptr), texture(nullptr) {}

UI::~UI() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    if (texture) SDL_DestroyTexture(texture);
    SDL_Quit();
}

void UI::generatePathsForVector() {
    imagePaths.push_back("ui files/titlebg.png");
    imagePaths.push_back("ui files/player1.png");
    imagePaths.push_back("ui files/player2.png");
}

bool UI::loadImages(const vector<string>& paths) {
    for (const auto& path : paths) {
        SDL_Surface* loadedSurface = IMG_Load(path.c_str());
        if (!loadedSurface) {
            cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << endl;
            return false;
        }
        SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);
        if (!newTexture) {
            cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << endl;
            return false;
        }
        textures.push_back(newTexture);
    }
    return true;
}

bool UI::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "No se pudo inicializar SDL: " << SDL_GetError() << ::endl;
        return false;
    }

    window = SDL_CreateWindow(
        "Maze Craze (Memory Leaks)",
         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        cerr << "La ventana no pudo ser creada: " << SDL_GetError() << endl;
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        cerr << "El renderizador no pudo ser creado: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        cerr << "SDL_image no pudo ser inicializado. IMG_Error: " << IMG_GetError() << endl;
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf no pudo ser inicializado. TTF_Error: " << TTF_GetError() << std::endl;
        return false;
    }

    generatePathsForVector();

    if (!loadImages(imagePaths)) {
        cerr << "Las imagenes no pudieron ser creadas." << endl;
        return false;
    }

    return true;
}

void UI::renderTitleScreen() {
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, textures[0], nullptr, nullptr);

    SDL_Rect playButton = {600, 1665, 700, 200};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &playButton);

    SDL_RenderPresent(renderer);
}

void UI::renderMainProgram(const Backend& backend, int num) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    const auto& grid = backend.getGrid();
    for (int i = 0; i < GRID_ROWS; ++i) {
        for (int j = 0; j < GRID_COLS; ++j) {
            if (grid[i][j] == num) {
                SDL_Rect player = {j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE};
                if (!textures.empty()) {
                    SDL_RenderCopy(renderer, textures[num], nullptr, &player);
                } else {
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                    SDL_RenderFillRect(renderer, &player);
                }
            }
        }
    }

    SDL_RenderPresent(renderer);
}

