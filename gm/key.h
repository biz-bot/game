#pragma once
#ifndef KEY_H
#define KEY_H
#include "include.h"
#include "render.h"
#include "mouse.h"

class KeyButton
{
public:
	double xtransf = 0.0, ytransf = 10.0, ztransf = 0.0;
	char  forward = 'w', right = 'd', left = 'a', back = 's';
	bool forwardB = false, rightB = false, leftB = false, backB = false;
	
	int keys();
};

void keyDown(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);
void SpecialKeysDown(int  key, int x, int ó);
void SpecialKeysUp(int  key, int x, int ó);
void time(int value);
extern KeyButton but;


#endif