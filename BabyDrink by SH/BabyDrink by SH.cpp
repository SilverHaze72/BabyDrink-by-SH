#include "SDL.h"
#undef main
#include "baby.h"
#include <iostream>

using namespace std;

SDL_Window* mWindow{ nullptr }; // ma fen�tre 
SDL_Renderer* mRenderer{ nullptr }; // mon rendu
bool isRunning;
bool fullscreen;
void handleEvents();
void update();
void render();


int main() {

    fullscreen = false;
    int flags = 0;
    flags = SDL_WINDOW_RESIZABLE;
    if (fullscreen) {
        flags = flags | SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized!\n";



        mWindow = SDL_CreateWindow("BabyDrink", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, flags);
        if (mWindow) {
            std::cout << "Window Created!\n";
            SDL_SetWindowMinimumSize(mWindow, 100, 100);
        }

        mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
        if (mRenderer) {
            SDL_SetRenderDrawColor(mRenderer, 121, 121, 121, 255);
            std::cout << "Renderer created!\n";
            SDL_SetRenderDrawBlendMode(mRenderer, SDL_BLENDMODE_BLEND);
            isRunning = true;
        }
    }

    while (isRunning) {
        handleEvents();
        update();
        render();
    }

    cout << "Loading success...";
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
    return 0;
}

void handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);


    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

//simple render function
void render() {
    SDL_SetRenderDrawColor(mRenderer, 200, 255, 255, 255);
    SDL_RenderClear(mRenderer);

    //your stuff to render would typically go here.
    SDL_RenderPresent(mRenderer);
}

//simple update function
void update() {
    //if things could update the code would go in here.
}