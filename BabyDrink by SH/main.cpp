//#include "SDL.h"
//#include "SDL_image.h"
#undef main

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;
#include "baby.h"
#include "shopping_List.h"
#include <list>


/*
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
*/

void clrscr()
{
	system("cls");
};

int main(int argc, char* args[])
{

	/*
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

	*/

	string ingredient;
	int laitTot, laitRest, drinkStat, regStat, quantIngr;
	int choiceMenu;
	int newTimeAlert, hours, minutes;
	bool drink = true, regur = true;
	string n;
	int q;

	start:
		cout << " ---------------------" << endl;
		cout << "||                   ||" << endl;
		cout << "||     Baby Drink    ||" << endl;
		cout << "||                   ||" << endl;
		cout << " ---------------------" << endl << endl;

		cout << "       Main menu     " << endl << endl;
		cout << "1 - Prise de biberon" << endl;
		cout << "2 - Ajouter une alerte" << endl;
		cout << "3 - Liste de course" << endl;
		cout << "4 - Quitter" << endl << endl;
		cout << "Choix: ";
		cin >> choiceMenu;

	if (choiceMenu >= 1 && choiceMenu <= 4) {
		
		switch (choiceMenu) {

			case 1:
				clrscr();

				biberon bib;

				cout << "Le biberon a t-il ete bu ?" << endl << "1 - oui" << endl << "2 - non" << endl << "Reponse : ";
				cin >> drinkStat;
				cout << "entrer la quantite de lait dans le biberon (en cl) : ";
				cin >> laitTot;

				if (drinkStat == 2) {
					laitRest = laitTot;
					regur = false;
				}
				
				cout << "entrer la quantite restante dans le biberon (en cl) : ";
				cin >> laitRest;
				cout << " Le bebe a t-il regurgite ?" << endl << "1 - oui" << endl << "2 - non" << endl << "Reponse : ";
				cin >> regStat;
				cout << endl;

				if (drinkStat == 1)
					drink = true;
				else if (drinkStat == 2)
					drink = false;

				if (regStat == 1)
					regur = true;
				else if (regStat == 2)
					regur = false;

				bib.biberonStatut(drink, laitTot, laitTot - laitRest, regur);
				break;

			case 2:
				clrscr();

				alert newAlert;

				cout << "Dans combien de temps voulez vous votre prochaine alert ?" << endl;
				cout << "Nombre d'heures : ";
				cin >> hours;

				retryMinutes:
					cout << "Nombre de minutes : ";
					cin >> minutes;

					if (minutes < 0 || minutes > 59){
						cout << "Error : minutes are invalid, please enter valid values between 0 and 59." << endl;
						goto retryMinutes;
					}

				newTimeAlert = hours * 3600000 + minutes * 60000;
				newAlert.addalert(newTimeAlert);
				break;

			case 3:
				system("exit");
				return 0;
				break;
				
			case 4:
				system("exit");
				return 0;
				break;
		}
		goto start;
	}

	//Liste de course
	cout << "entrer le nom d'un ingredient : ";
	cin >> ingredient;
	cout << "entrer la quatité de " << ingredient << " pour un biberon : ";
	cin >> quantIngr;

	course produit1;
	produit1.addProduit(ingredient, quantIngr);


	return 0;
}