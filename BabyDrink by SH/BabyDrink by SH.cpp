#include "SDL.h"
#undef main

#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include "baby.h"
#include "Button.cpp"
//#include "mainView.cpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(){


	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//initalise SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL ne peut être initialisé ! SDL_Error: %s\n" << SDL_GetError();
	}
	else
	{
		//creer window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			cout << "Window ne peut être créer ! SDL_Error: %s\n" << SDL_GetError();
		}

		else
		{
			//Fait apparaitre window
			screenSurface = SDL_GetWindowSurface(window);

			//remplis la window en couleur
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 133, 0, 0));

			//Update window
			SDL_UpdateWindowSurface(window);

			//fonction pour garder la window ouvert
			SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
		}
	}
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();







	/*
	//Creation et mise en etat d'un biberon
	biberon bib;

	int laitTot, laitRest, drinkStat, regStat;
	bool drink, regur;

	cout << "Le biberon a t-il ete bu ?" << endl << "1 - oui" << endl << "2 - non" << endl << "Reponse : ";
	cin >> drinkStat;
	cout << "entrer la quantite de lait dans le biberon (en cl) : ";
	cin >> laitTot;
	cout << "entrer la quantite restante dans le biberon (en cl) : ";
	cin >> laitRest;
	cout << " Le bebe a t-il regurgite ?" << endl << "1 - oui" << endl << "2 - non" << endl << "Reponse : ";
	cin >> regStat;

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
	*/


	return 0;

}



