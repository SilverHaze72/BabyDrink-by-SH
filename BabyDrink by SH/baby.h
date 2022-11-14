#ifndef BABY_H
#define BABY_H


class alert {
public:
	int timer;


	//setter
	void addalert(int time) {
		timer = time;
	};

	//getter
	int getTime() {
		return timer;
	}
};

class biberon {

public:
	bool drinked;
	int quantity;
	int quantityDrink;
	bool regur;

public:

	//getter
	bool getDrinked() {
		return drinked;
	};

	int getQuantity() {
		return quantity;
	};

	int getQuantityD() {
		return quantityDrink;
	};
	bool getRegur() {
		return regur;
	};

	//contructor

	void biberonStatut(bool dri, int quant, int quantdri, bool reg) {
		drinked = dri;
		quantity = quant;
		quantityDrink = quantdri;
		regur = reg;
	};

};

class course {

	string produit;
	int number;

	//getter
	string getProduit() {
		return produit;
	};

	int getNumber() {
		return number;
	};

	//constructor
	void addProduit(string name, int quantity)
	{
		produit = name;
		number = quantity;
	};
};



#endif