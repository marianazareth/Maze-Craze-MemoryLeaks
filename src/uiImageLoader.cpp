#include "uiImageLoader.h"
#include <iostream>
using namespace std;

void ImageLoader::generatePathsForVector() {
    imagePaths.push_back("ui files/titlebg.png");
    imagePaths.push_back("ui files/player1.png");
    imagePaths.push_back("ui files/player2.png");
}

bool ImageLoader::loadImages(SDL_Renderer* renderer, const vector<string>& paths) {
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