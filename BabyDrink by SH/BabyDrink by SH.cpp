#include "SDL.h"
#undef main

#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include "baby.h"
//#include "mainView.cpp"



int main()

{

	int delayBib;

	cout << "Enter the time in seconds to be delayed:";

	cin >> delayBib;

	delayBib *= CLOCKS_PER_SEC;

	clock_t now = clock();

	while (clock() - now < delayBib);
	cout << "Message Show after delay that you entered" << endl;
	return 0;

}



