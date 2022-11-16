#include "SDL.h"
#undef main

#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include "baby.h"
//#include "mainView.cpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(){


	string ingredient;
	int laitTot, laitRest, drinkStat, regStat;
	bool drink, regur;

	/*
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


	/* Liste de course
	cout << "entrer le nom d'un ingredient : ";
	cin >> ingredient;
	cout << "entrer la quatité de " << ingredient << " pour un biberon : ";
	cin >> quantIngr;

	course produit1;
	produit1.addProduit(ingredient, quantIngr);
	*/




	return 0;

}



