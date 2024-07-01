#include "UI_ImageLoader.h"
#include "UI_Board.h"
#include "UI_Cell.h"
#include <iostream>
using namespace std;

UI_Cell uiCell;

void UI_Board::renderBoard(SDL_Renderer* renderer, int** playerBoard, int rowAmount, int colAmount) {
    for (int i = 0; i < rowAmount; i++) {
       for (int j = 0; j < colAmount; j++) {
            uiCell.renderCell(renderer, i, j);
            // Añadir ifs para renderizar los poderes
        } 
    }

    SDL_RenderPresent(renderer);
}