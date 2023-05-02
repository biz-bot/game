#include "key.h"

void keyDown(unsigned char key, int x, int y) {
	
	if (key == but.forward || key == toupper(but.forward)) { but.forwardB = true; }
	if (key == but.back    || key == toupper(but.back))    { but.backB = true; }
	if (key == but.left    || key == toupper(but.left))    { but.leftB = true; }
	if (key == but.right   || key == toupper(but.right))   { but.rightB = true; }
	if (key == 27) exit(0);
	//keys();
	//glutPostRedisplay();
}
void keyUp(unsigned char key, int x, int y) {
	if (key == but.forward || key == toupper(but.forward)) { but.forwardB = false; }
	if (key == but.back    || key == toupper(but.back))    { but.backB = false; }
	if (key == but.left    || key == toupper(but.left))    { but.leftB = false; }
	if (key == but.right   || key == toupper(but.right))   { but.rightB = false; }
	//glutPostRedisplay();
	//keys();
}
void SpecialKeysDown(int  key, int x, int ó) {
	
	glutPostRedisplay();
}
void SpecialKeysUp(int  key, int x, int ó) {

	glutPostRedisplay();
}

int KeyButton::keys() {
	float pi = 3.1415926535f;
	//stop();
	if (forwardB == true  ) {
		xtransf -= cos(mouse.Get_rotx());
		ztransf -= sin(mouse.Get_rotx());
	
	}
	if (rightB == true ) {
		xtransf -= cos(mouse.Get_rotx() + pi / 2);
		ztransf -= sin(mouse.Get_rotx() + pi / 2);
	}
	if (leftB == true ) {
		xtransf += cos(mouse.Get_rotx() + pi /2);
		ztransf += sin(mouse.Get_rotx() + pi /2);
	}
	if (backB == true ) {
		xtransf += cos(mouse.Get_rotx());
		ztransf += sin(mouse.Get_rotx());
	}
	//glutPostRedisplay();
	//stop();
	return 0;
}