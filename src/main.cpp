#include <iostream>
#include "backend.h"
#include "UI_TitleScreen.h"
#include "uiMain.h"

int main(int argc, char* argv[]) {
    Backend backend;
    UI_TitleScreen UI_TitleScreen;
    UI_MAIN UI_Main;

    enum GameState {
        TITLE_SCREEN, MAIN_PROGRAM, WIN_SCREEN
    };

    if (!UI_Main.initialize()) {
        return 1;
    }

    GameState gameState = TITLE_SCREEN;

    SDL_Renderer* renderer = UI_Main.getRenderer();
    SDL_Event event;
    bool running = true;
    char direction = 'x';

    while (running) {
        if (gameState == TITLE_SCREEN) {
            UI_TitleScreen.runTitleScreen(renderer);
        } else if (gameState == MAIN_PROGRAM) {
            // UI_Main.runMainProgram(matrix, playerNumber); // AQUI SE UTILIZAN LOS VALORES DEL BACKEND PARA RENDERIZAR
        }

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (gameState == TITLE_SCREEN) {
                if (UI_TitleScreen.handleEvents(event)) {
                    gameState = MAIN_PROGRAM;
                }
            } else if (gameState == MAIN_PROGRAM) {
                // UI_Main.handleEvents(event, gameState);
            }
        }
    }

    return 0;
}
