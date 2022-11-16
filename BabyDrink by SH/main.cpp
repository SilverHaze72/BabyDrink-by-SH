#include "SDL.h"
#undef main

#include <iostream>
#include <string>
#include <ctime>
#include "SDL_image.h"
#include <stdio.h>
#include <cmath>
using namespace std;
#include "baby.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: %s" << endl << SDL_GetError();
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window could not be created! SDL_Error: %s" << endl << SDL_GetError();
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);

			//Fill the surface white
			SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 130, 220, 255));

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Nothing to load
	return success;
}

void close()
{
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		cout << "Failed to initialize!" << endl;
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			cout << "Failed to load media!" << endl;
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Render red filled quad
				SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
				SDL_RenderFillRect(gRenderer, &fillRect);

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Free resources and close SDL
	close();


	string ingredient;
	int laitTot, laitRest, drinkStat, regStat, quantIngr;
	bool drink = true, regur = true;

	

	//Creation et mise en etat d'un biberon
	biberon bib;

	cout << "Le biberon a t-il ete bu ?" << endl << "1 - oui" << endl << "2 - non" << endl << "Reponse : ";
	cin >> drinkStat;
	cout << "entrer la quantite de lait dans le biberon (en cl) : ";
	cin >> laitTot;
	cout << "entrer la quantite restante dans le biberon (en cl) : ";
	cin >> laitRest;
	cout << " Le bebe a t-il regurgite ?" << endl << "1 - oui" << endl << "2 - non" << endl << "Reponse : ";
	cin >> regStat;
	cout << endl;

	if (drinkStat == 1)
		drink = true;
	else if(drinkStat == 2)
		drink = false;

	if (regStat == 1)
		regur = true;
	else if (regStat == 2)
		regur = false;

	bib.biberonStatut(drink, laitTot, laitTot - laitRest, regur);

	cout << bib.getDrinked() << "  " << bib.getQuantity() << "  " << bib.getQuantityD() << "  " << bib.getRegur();
	
	//fin de creation biberon


	//Liste de course
	cout << "entrer le nom d'un ingredient : ";
	cin >> ingredient;
	cout << "entrer la quatité de " << ingredient << " pour un biberon : ";
	cin >> quantIngr;

	course produit1;
	produit1.addProduit(ingredient, quantIngr);
	




	return 0;

}