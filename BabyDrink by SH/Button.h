#ifndef BUTTON_H
#define BUTTON_H
#include "Mouse.h"

class Button
{
public:
	SDL_Texture * Lex;
	SDL_Rect srect, drect;
	bool isSelected = false;

	Button();
	virtual ~Button();

	void update(Mouse&);
};

#endif // !BUTTON_H



