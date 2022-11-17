//////////////////////////
//						//
//      Baby drink		//
//	by BOURION TiTouan  //
//   aka Silver_Haze_   //
//						//
//////////////////////////

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
#include <list>


/*
//dimension de la fenêtre
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Start SDL et creer la fenêtre
bool init();

//shuts down SDL
void close();

//Mise en place de la fenêtre
SDL_Window* gWindow = NULL;

//Suface contenu dans la fenêtre
SDL_Surface* gScreenSurface = NULL;

//Rendu de la fenêtre
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Init flag "sucess"
	bool success = true;

	//Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL ne peut etre initialisé ! SDL_Error: %s" << endl << SDL_GetError();
		success = false;
	}
	else
	{
		//creer la fenêtre
		gWindow = SDL_CreateWindow("Baby Drink", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window ne peut etre cree ! SDL_Error: %s" << endl << SDL_GetError();
			success = false;
		}
		else
		{
			//recupère la surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);

			//Remplis la surface en blanc
			SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 130, 220, 255));

			//Met à jour la surface
			SDL_UpdateWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	//Load le flag "sucess
	bool success = true;

	return success;
}

void close()
{
	//Destruit window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quitte les sous-systèmes SDL
	SDL_Quit();
}
*/

//Clear console
void clrscr()
{
	system("cls");
};

int main(int argc, char* args[])
{

	/*
	//Start SDL et creer la fenêtre
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
			//flag de la boucle principale
			bool quit = false;

			//Event handler
			SDL_Event e;

			//tant que l'application est ON
			while (!quit)
			{
				//Traitement des events de la file d'attente
				while (SDL_PollEvent(&e) != 0)
				{
					//Requête utilisateur : quitter
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Test de rendu non fonctionnel (mis en attente)
				SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
				SDL_RenderFillRect(gRenderer, &fillRect);

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//close SDL et sous-systèmes
	close();

	*/

	//Initalisation des variables
	string ingredient;
	int laitTot, laitRest, drinkStat, regStat, quantIngr;
	int choiceMenu;
	int newTimeAlert, hours, minutes;
	bool drink = true, regur = true;

	//label Start
	start:
		//Interface console (Main Menu)
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
		//Choix menu
		cout << "Choix: ";
		cin >> choiceMenu;

		//verif de choix valide
	if (choiceMenu >= 1 && choiceMenu <= 4) {
		//traitement du choix pour redirection
		switch (choiceMenu) {

			case 1:
				//clear console et creation biberon
				clrscr();

				biberon bib;

				cout << "Le biberon a t-il ete bu ?" << endl << "1 - oui" << endl << "2 - non" << endl << "Reponse : ";
				cin >> drinkStat;
				cout << "entrer la quantite de lait dans le biberon (en cl) : ";
				cin >> laitTot;
				//verif biberon bu et redirection sur la suite d'entrer des données liées au biberon
				if (drinkStat == 2) {
					laitRest = laitTot;
					regur = false;
				}
				else
				{
					cout << "entrer la quantite restante dans le biberon (en cl) : ";
					cin >> laitRest;
					cout << " Le bebe a t-il regurgite ?" << endl << "1 - oui" << endl << "2 - non" << endl << "Reponse : ";
					cin >> regStat;
					cout << endl;
				}
				//traitement des données pour les rendrent lisible par la classe
				if (drinkStat == 1)
					drink = true;
				else if (drinkStat == 2)
					drink = false;

				if (regStat == 1)
					regur = true;
				else if (regStat == 2)
					regur = false;
				//redirection des données vers la classe
				bib.biberonStatut(drink, laitTot, laitTot - laitRest, regur);
				break;

			case 2:
				//clear console et creation de l'alert
				clrscr();

				alert newAlert;

				//recuperation du temps avant l'alarme defini par l'utilisateur
				cout << "Dans combien de temps voulez vous votre prochaine alert ?" << endl;
				cout << "Nombre d'heures : ";
				cin >> hours;

				retryMinutes:
					cout << "Nombre de minutes : ";
					cin >> minutes;
					//verif de données valide
					if (minutes < 0 || minutes > 59){
						cout << "Error : minutes are invalid, please enter valid values between 0 and 59." << endl;
						goto retryMinutes;
					}
					//redirection des données vers la classe
				newTimeAlert = hours * 3600000 + minutes * 60000;
				newAlert.addalert(newTimeAlert);
				break;

			case 3:
				//Liste de course
				cout << "entrer le nom d'un ingredient : ";
				cin >> ingredient;
				cout << "entrer la quatité de " << ingredient << " pour un biberon : ";
				cin >> quantIngr;

				course produit1;
				produit1.addProduit(ingredient, quantIngr);

			case 4:
				//solution exit systeme
				system("exit");
				return 0;
				break;
		}
		goto start;
	}

	return 0;
}