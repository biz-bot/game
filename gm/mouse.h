#pragma once
#ifndef MOUSE_H
#define MOUSE_H
#include "include.h"
#include "file.h"

extern int windowWidth, windowHeight;

void mouseactiv(int x, int y);
void mousepassiv(int x, int y);

class mouseCoord : public coordinates
{
public:
	mouseCoord() {
		rotx = 0.0;
		roty = 0.0;
		sensax = 1;
		sensay = 1;
	}
	//~mouseCoord();
	double Get_xnorm() {return xnorm;}
	double Get_ynorm() { return ynorm; }
	double Get_znorm() { return znorm; }

	double Get_rotx() { return rotx; }
	double Get_roty() { return roty; }

	double Get_sensax() { return sensax; }
	double Get_sensay() { return sensay; }

	void Set_xnorm(int i) { this->xnorm = i; }
	void Set_ynorm(int i) { this->ynorm = i; }
	void Set_znorm(int i) { this->znorm = i; }

	void Set_rotx(int i) { this->rotx = i; }
	void Set_roty(int i) { this->roty = i; }

	void Set_sensax(int i) { this->sensax = i; }
	void Set_sensay(int i) { this->sensay = i; }
	
	coordinates Get_coordinates() { return CoordMouse; }
	

	int mouserot(int x, int y);
private:
	
	double xnorm, ynorm, znorm;
	double rotx, roty;
	double sensax , sensay ;
	coordinates CoordMouse;
};
extern mouseCoord mouse;
#endif