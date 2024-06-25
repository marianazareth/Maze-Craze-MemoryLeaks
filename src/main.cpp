#include <iostream>
#include "backend.h"
#include "ui.h"

int main(int argc, char* argv[]) {
    Backend backend;
    UI ui;

    if (!ui.initialize()) {
        return 1;
    }

    bool running = true;
    char direction = '\0';

    while (running) {
        running = ui.processInput(direction);
        if (direction != '\0') {
            backend.moveCube(direction);
            direction = '\0';
        }
        ui.renderMainProgram(backend, 1);
        SDL_Delay(16); // Aproximadamente 60 FPS
    }

    return 0;
}